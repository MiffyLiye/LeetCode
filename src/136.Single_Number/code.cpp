#include "code.h"
#include <limits>

using namespace std;

namespace Single_Number
{
    int single_number_xor(vector<int>& nums)
    {
        int x{0};
        for (auto i : nums)
        {
            x ^= i;
        }
        return x;
    }

    void apply(int x, vector<char>& record)
    {
        for (auto i = 0u; i < numeric_limits<int>::digits + 1; i++)
        {
            if ((x & (1 << i)) != 0)
            {
                record[i]++;
                record[i] %= 2;
            }
        }
    }

    int extract(vector<char>& record)
    {
        int x{0};
        for (auto i = 0u; i < numeric_limits<int>::digits + 1; i++)
        {
            x = (record[i] == 1) ? (x | (1 << i)) : x;
        }
        return x;
    }

    int single_number(vector<int>& nums)
    {
        vector<char> record(numeric_limits<int>::digits + 1);
        for (auto i : nums)
        {
            apply(i, record);
        }
        return extract(record);
    }

    int Solution::singleNumber(vector<int>& nums)
    {
        return single_number_xor(nums);
    }
}