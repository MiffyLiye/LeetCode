#pragma once

#include <unordered_map>
#include <limits>
#include <stdexcept>
#include <string>

namespace LRU_Cache
{
    class LRUCache
    {
    private:
        struct Node
        {
            int older;
            int younger;
            int value;
        };
        size_t capacity;
        std::unordered_map<int, Node> data;
        int youngest;
        int oldest;

        inline void insert(int key, int value)
        {
            if (data.size() == capacity)
            {
                pop();
            }
            if (data.size() == 0)
            {
                data.insert({key, {key, key, value}});
                oldest = key;
                youngest = key;
            }
            else
            {
                data.insert({key, {youngest, key, value}});
                data[youngest].younger = key;
                youngest = key;
            }
        }

        inline void modify(std::unordered_map<int, Node>::iterator i, int value)
        {
            auto key = i->first;
            auto& node = i->second;
            node.value = value;
            if (key == youngest)
            { ;
            }
            else if (key == oldest)
            {
                oldest = node.younger;
                data[oldest].older = oldest;
                data[youngest].younger = key;
                node.older = youngest;
                node.younger = key;
                youngest = key;
            }
            else
            {
                data[node.older].younger = node.younger;
                data[node.younger].older = node.older;
                data[youngest].younger = key;
                node.younger = key;
                node.older = youngest;
                youngest = key;
            }
        }

        inline void pop()
        {
            auto key = oldest;
            oldest = data[key].younger;
            data[oldest].older = oldest;
            data.erase(data.find(key));
        }

    public:
        LRUCache(int capacity_) : capacity{0}, data{}, youngest{}, oldest{}
        {
            auto capacity_max = std::numeric_limits<size_t>::max();
            if (capacity_ < 0 || static_cast<unsigned int>(capacity_) > capacity_max)
            {
                throw std::runtime_error("cannot support capacity that is longer than " + std::to_string(capacity_max));
            }

            capacity = capacity_ < 0 ? 0u : static_cast<size_t>(capacity_);
        }

        int get(int key)
        {
            if (data.find(key) == data.end())
            {
                return -1;
            }
            else
            {
                auto value = data[key].value;
                modify(data.find(key), value);
                return value;
            }
        }

        void set(int key, int value)
        {
            if (data.find(key) != data.end())
            {
                modify(data.find(key), value);
            }
            else
            {
                insert(key, value);
            }
        }

    };
}