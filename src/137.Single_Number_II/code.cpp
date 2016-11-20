#include "code.h"
#include <limits>

using namespace std;

namespace Single_Number_II{
    void apply(int x, vector<char>& record) {
        for (int i = 0; i < numeric_limits<int>::digits + 1; i++) {
            record[i] += ((x & (1 << i)) != 0) ? 1 : 0;
            record[i] %= 3;
        }
    }

    int extract(vector<char>& record) {
        int x {0};
        for (int i = 0; i < numeric_limits<int>::digits + 1; i++) {
            x = (record[i] == 1) ?  (x | (1 << i)) : x;
        }
        return x;
    }

    int single_number(vector<int>& nums) {
        vector<char> record (numeric_limits<int>::digits + 1);
        for (auto i : nums) {
            apply(i, record);
        }
        return extract(record);
    }

    int Solution::singleNumber(vector<int>& nums) {
        return single_number(nums);
    }
}