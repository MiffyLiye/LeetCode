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
            modify(data.find(key), value);
            return value;
        }
    }
    
    void set(int key, int value) {
        if (data.find(key) != data.end()) {
            modify(data.find(key), value);
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

    inline void insert(int key, int value) {
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

    inline void modify(unordered_map<int, Node>::iterator i, int value) {
        auto key = i->first;
        auto& node = i->second;
        node.value = value;
        if (key == youngest) {
            ;
        }
        else if (key == oldest) {
            oldest = node.younger;
            data[oldest].older = oldest;            
            data[youngest].younger = key;
            node.older = youngest;
            node.younger = key;
            youngest = key;
        }
        else {
            data[node.older].younger = node.younger;
            data[node.younger].older = node.older;
            data[youngest].younger = key;
            node.younger = key;
            node.older = youngest;
            youngest = key;
        }
    }

    inline void pop() {
        auto key = oldest;
        oldest = data[key].younger;
        data[oldest].older = oldest;
        data.erase(data.find(key));
    }
};

int main()
{
    LRUCache x(2);
    x.set(2,1);
    x.set(2,2);
    cout << x.get(2) << '\t';
    x.set(1,1);
    x.set(4,1);
    cout << x.get(2) << '\t';
    cout << '\n';

    return 0;
}