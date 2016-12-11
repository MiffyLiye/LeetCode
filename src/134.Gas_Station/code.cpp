#include "code.h"
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

namespace Gas_Station
{
    int can_complete_circuit(vector<int>& gas, vector<int>& cost)
    {
        auto int_max = numeric_limits<unsigned int>::max() / 2;
        if (gas.size() > int_max || cost.size() > int_max)
        {
            throw runtime_error("cannot support circuit that is longer than " + to_string(int_max));
        }
        for (auto i : gas)
        {
            if (i < 0)
            {
                throw runtime_error("cannot support gas that is smaller than 0");
            }
        }
        for (auto i : cost)
        {
            if (i < 0)
            {
                throw runtime_error("cannot support cost that is smaller than 0");
            }
        }

        int survived;
        size_t begin{};
        bool begin_set{false};
        size_t end{};
        vector<int> gain(gas.size());
        for (auto i = 0u; i < gas.size(); i++)
        {
            gain[i] = gas[i] - cost[i];
            if (!begin_set && gain[i] >= 0)
            {
                begin = i;
                begin_set = true;
            }
        }
        if (!begin_set)
        {
            return -1;
        }
        end = begin;
        survived = gain[begin];
        while (begin < gas.size())
        {
            while (end - begin < gas.size())
            {
                if (survived >= 0)
                {
                    end++;
                    survived = survived + gain[end % gas.size()];
                }
                else
                {
                    if (end >= gas.size() - 1)
                    {
                        return -1;
                    }
                    begin = end + 1;
                    end = begin;
                    survived = gain[begin];
                }
            }
            if (survived >= 0)
            {
                return static_cast<int>(begin);
            }
        }
        return -1;
    }

    int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        return can_complete_circuit(gas, cost);
    }
}