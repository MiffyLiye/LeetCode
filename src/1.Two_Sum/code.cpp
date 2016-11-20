#include "code.h"
#include <set>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;

namespace Two_Sum
{
    vector<int> get_index(vector<int>& numbers, int x, int y)
    {
        auto int_max = numeric_limits<int>::max();
        if (numbers.size() > static_cast<size_t>(int_max))
        {
            throw runtime_error(string{"cannot support vector that is longer than " + to_string(int_max)});
        }

        vector<int> index{0, 0};
        vector<bool> is_done{false, false};
        for (auto i = 0; i < static_cast<int>(numbers.size()) && (!is_done[0] || !is_done[1]); i++)
        {
            if (!is_done[0] && numbers[i] == x)
            {
                index[0] = i;
                is_done[0] = true;
                continue;
            }
            else if (!is_done[1] && numbers[i] == y)
            {
                index[1] = i;
                is_done[1] = true;
                continue;
            }
        }
        if (!is_done[0] || !is_done[1])
        {
            index[0] = 0;
            index[1] = 0;
        }
        else
        {
            sort(index.begin(), index.end());
        }
        return index;
    }

    vector<int> two_sum(vector<int>& numbers, int target)
    {
        set<int> s;
        vector<int> index{0, 0};
        for (auto x:numbers)
        {
            s.insert(x);
        }
        for (auto x = s.begin(); x != s.end(); x++)
        {
            if (*x * 2 <= target)
            {
                if (s.find(target - *x) != s.end())
                {
                    index = get_index(numbers, *x, target - *x);
                    if (index[0] == index[1])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        return index;
    }

    vector<int> Solution::twoSum(vector<int>& numbers, int target)
    {
        auto index = two_sum(numbers, target);
        return index;
    }
}
