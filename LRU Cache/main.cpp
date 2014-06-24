#include<iostream>
#include<map>
#include<limits>

using namespace std;
using clock_t_ = size_t;
class LRUCache{
public:
    LRUCache(int capacity_) : capacity {capacity_}, sz {0}, clock {0}, data {}, key_time {}, time_key{} {
        capacity = (capacity >= 0) ? capacity : 0;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        else {
            auto value = data[key];
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
    int capacity;
    int sz;
    clock_t_ clock;
    map<int, int> data;
    map<int, clock_t_> key_time;
    map<clock_t_, int> time_key;

    void reset_clock() {
        map<clock_t_, int> time_key_new;
        clock_t_ clock = 0;
        while (time_key.size() != 0) {
            auto i = time_key.begin();
            key_time[i->second] = clock;
            time_key_new.insert(pair<clock_t_, int>(clock, i->second));
            time_key.erase(i);
            clock++;
        }
        time_key.swap(time_key_new);
    }

    void modify(int key, int value) {
        data[key] = value;
        time_key.erase(time_key.find(key_time[key]));
        key_time[key] = clock;
        time_key.insert(pair<clock_t_, int>(clock, key));
        clock++;
        if (clock == numeric_limits<clock_t_>::max()) {
            reset_clock();
        }
    }

    int pop() {
        auto i = time_key.begin();
        auto time = i->first;
        auto key = i->second;
        data.erase(data.find(key));
        time_key.erase(time_key.find(time));
        key_time.erase(key_time.find(key));
        sz--;

        return key;
    }

    void insert(int key, int value) {
        if (sz == capacity) {
            pop();
        }
        data.insert(pair<int, int>(key, value));
        key_time.insert(pair<int, clock_t_>(key, clock));
        time_key.insert(pair<clock_t_, int>(clock, key));
        clock++;
        sz++;
    }
};

int main()
{
    LRUCache x(2);
    x.set(2,1);
    x.set(1,1);
    cout << x.get(2) << endl;
    x.set(4,1);
    cout << x.get(1) << endl;
    cout << x.get(2) << endl;

    return 0;
}