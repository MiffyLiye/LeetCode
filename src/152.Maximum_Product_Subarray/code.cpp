#include "code.h"
#include <algorithm>

using namespace std;

namespace Maximum_Product_Subarray
{
    int max_product(vector<int>& nums) {
        // spatial complexity O(1)
        // temporal complexity O(n)
        int negative = 0;
        int positive = 0;
        int maximum = nums[0];
        for (auto n : nums) {
            if (n < 0) {
                if (positive == 0) {
                    positive = negative * n;
                    negative = n;
                }
                else {
                    positive *= n;
                    negative *= n;
                    swap(positive, negative);
                }
            }
            else if (n > 0) {
                if (positive == 0) {
                    positive = n;
                    negative *= n;
                }
                else {
                    positive *= n;
                    negative *= n;
                }
            }
            else {
                positive = 0;
                negative = 0;
            }

            if (positive != 0) {
                maximum = max(positive, maximum);
            }
            if (negative != 0) {
                maximum = max(negative, maximum);
            }
            if (n == 0) {
                maximum = max(n, maximum);
            }
        }
        return maximum;
    }
    double max_product(double A[], int n) {
        // spatial complexity O(n)
        // temporal complexity O(n^2)
        if (n < 1) {
            return 0;
        }
        else if (n == 1) {
            return A[0];
        }

        size_t sz = static_cast<size_t>(n);

        vector<double> prod(sz);
        for (auto i = 0u; i < sz; i++) {
            prod[i] = n;
        }

        double maximum = prod[0];
        for (auto i = 1u; i < sz; i++) {
            for (auto t = 1u; t <= i; t++) {
                auto j = i - t;
                prod[j] = prod[j] * n;
                maximum = (maximum < prod[j]) ? prod[j] : maximum;
            }
        }

        return maximum;
    }

    int Solution::maxProduct(vector<int>& nums) {
        return max_product(nums);
    }
}