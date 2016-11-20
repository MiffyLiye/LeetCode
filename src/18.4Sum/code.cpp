#include "code.h"
#include <algorithm>

using namespace std;

namespace Four_Sum
{
    vector<vector<int>> four_sum(vector<int> num, int target)
    {
        sort(num.begin(), num.end());

        vector<vector<int>> result{};

        for (size_t h = 0; h < num.size(); h++)
        {
            if (h >= 1 && num[h - 1] == num[h])
            {
                continue;
            }
            for (size_t i = h + 1; i < num.size(); i++)
            {
                if (i - 1 >= h + 1 && num[i - 1] == num[i])
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
                    auto sum = num[h] + num[i] + num[j] + num[k];
                    if (sum < target)
                    {
                        j++;
                    }
                    else if (sum > target)
                    {
                        k--;
                    }
                    else
                    {
                        result.push_back({num[h], num[i], num[j], num[k]});
                        j++;
                        k--;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> Solution::fourSum(vector<int>& num, int target)
    {
        return four_sum(num, target);
    }
}
