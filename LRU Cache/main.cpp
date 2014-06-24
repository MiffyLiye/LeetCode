#include<iostream>
#include<unordered_map>
#include<map>
#include<limits>

using namespace std;
using clock_t_ = unsigned int;
static_assert(numeric_limits<clock_t_>::max() >= numeric_limits<int>::max(), "clock range not large enough");

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
    int capacity;
    int sz;
    clock_t_ clock;
    unordered_map<int, int> data;
    unordered_map<int, clock_t_> key_time;
    map<clock_t_, int> time_key;

    inline void reset_clock() {
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

    inline void modify(unordered_map<int, int>::iterator i, int value) {
        auto key = i->first;
        i->second = value;
        time_key.erase(time_key.find(key_time[key]));
        key_time[key] = clock;
        time_key.insert(pair<clock_t_, int>(clock, key));

        clock++;
        
        if (clock == numeric_limits<clock_t_>::max()) {
            reset_clock();
        }
    }

    inline int pop() {
        auto i = time_key.begin();
        auto time = i->first;
        auto key = i->second;
        data.erase(data.find(key));
        time_key.erase(time_key.find(time));
        key_time.erase(key_time.find(key));
        sz--;

        return key;
    }

    inline void insert(int key, int value) {
        if (sz == capacity) {
            pop();
        }
        data.insert(pair<int, int>(key, value));
        key_time.insert(pair<int, clock_t_>(key, clock));
        time_key.insert(pair<clock_t_, int>(clock, key));

        clock++;
        sz++;

        if (clock == numeric_limits<clock_t_>::max()) {
            reset_clock();
        }
    }
};

int main()
{
    cout << numeric_limits<clock_t_>::max() << '\n';
    LRUCache x(2);
    x.set(2,1);
    x.set(1,1);
    cout << x.get(2) << '\t';
    x.set(4,1);
    cout << x.get(1) << '\t';
    cout << x.get(2) << '\t';
    cout << '\n';

    return 0;
}