#include "code.h"

using namespace std;

namespace Find_Minimum_in_Rotated_Sorted_Array{
    int find_min(vector<int>& num) {
        size_t first = 0;
        size_t last = num.size() - 1;

        while (first != last) {
            size_t middle = first + (last - first)/2;
            if (num[middle] <= num[last]) {
                last = middle;
            }
            else {
                first = middle + 1;
            }
        }
        return num[first];
    }

    int Solution::findMin(vector<int> &num) {
        return find_min(num);
    }
}