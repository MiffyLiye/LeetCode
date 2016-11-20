#include "code.h"

#include <algorithm>

using namespace std;

namespace Three_Sum_Closest
{
    int three_sum_closest(vector<int> num, int target)
    {
        sort(num.begin(), num.end());

        int diff = -1;
        int closest_sum{};

        for (size_t i = 0; i < num.size(); i++)
        {
            if (i >= 1 && num[i - 1] == num[i])
            {
                continue;
            }
            size_t j = i + 1;
            size_t k = num.size() - 1;
            while (j < k)
            {
                if (j - 1 >= i + 1 && num[j - 1] == num[j])
                {
                    j++;
                    continue;
                }
                if (k + 1 <= num.size() - 1 && num[k] == num[k + 1])
                {
                    k--;
                    continue;
                }
                auto sum = num[i] + num[j] + num[k];
                if (sum < target)
                {
                    if ((target - sum) < diff || diff < 0)
                    {
                        diff = target - sum;
                        closest_sum = sum;
                    }
                    j++;
                }
                else if (sum > target)
                {
                    if ((sum - target) < diff || diff < 0)
                    {
                        diff = sum - target;
                        closest_sum = sum;
                    }
                    k--;
                }
                else
                {
                    return target;
                }
            }
        }
        return closest_sum;
    }

    int Solution::threeSumClosest(vector<int>& num, int target)
    {
        return three_sum_closest(num, target);
    }
}
