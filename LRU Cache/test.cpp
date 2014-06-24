#include<iostream>
#include<unordered_map>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity_) : capacity {0}, data {}, youngest {}, oldest {} {
        capacity = capacity_ < 0 ? 0 : capacity_;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        else {
            auto value = data[key].value;
            modify(key, value);
            return value;
        }
    }
    
    void set(int key, int value) {
        if (data.find(key) != data.end()) {
            modify(key, value);
        }
        else {
            insert(key, value);
        }
    }
private:
    struct Node {
        int older;
        int younger;
        int value;
    };
    size_t capacity;
    unordered_map<int, Node> data;
    int youngest;
    int oldest;

    void insert(int key, int value) {
        if (data.size() == capacity) {
            pop();
        }
        if (data.size() == 0) {
            data.insert(pair<int, Node>(key, {key, key, value}));
            oldest = key;
            youngest = key;
        }
        else {
            data.insert(pair<int, Node>(key, {youngest, key, value}));
            data[youngest].younger = key;
            youngest = key;
        }
    }

    void modify(int key, int value) {
        data[key].value = value;
        if (key == youngest) {
            ;
        }
        else if (key == oldest) {
            oldest = data[key].younger;
            data[oldest].older = oldest;            
            data[youngest].younger = key;
            data[key].older = youngest;
            data[key].younger = key;
            youngest = key;
        }
        else {
            data[data[key].older].younger = data[key].younger;
            data[data[key].younger].older = data[key].older;
            data[youngest].younger = key;
            data[key].younger = key;
            data[key].older = youngest;
            youngest = key;
        }
    }

    void pop() {
        auto key = oldest;
        oldest = data[key].younger;
        data[oldest].older = oldest;
        data.erase(data.find(key));
    }
};

int main()
{
    LRUCache x(3);
    x.set(1,1);
    x.set(2,2);
    x.set(3,3);
    x.set(4,4);
    cout << x.get(4) << '\t';
    cout << x.get(3) << '\t';
    cout << x.get(2) << '\t';
    cout << x.get(1) << '\t';
    x.set(5,5);
    cout << x.get(1) << '\t';
    cout << x.get(2) << '\t';
    cout << x.get(3) << '\t';
    cout << x.get(4) << '\t';
    cout << x.get(5) << '\t';
    cout << '\n';

    return 0;
}