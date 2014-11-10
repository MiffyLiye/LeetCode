#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        return max_product(A, n);
    }
private:
    int max_product(int A[], int n) {
    // spatial complexity O(1)
    // temporal complexity O(n)
        int negative = 0;
        int positive = 0;
        int maximum = A[0];
        for (int i = 0; i < n; i++) {
            if (A[i] < 0) {
                if (positive == 0) {
                    positive = negative * A[i];
                    negative = A[i];
                }
                else {
                    positive *= A[i];
                    negative *= A[i];
                    swap(positive, negative);
                }
            }
            else if (A[i] > 0) {
                if (positive == 0) {
                    positive = A[i];
                    negative *= A[i];
                }
                else {
                    positive *= A[i];
                    negative *= A[i];
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
            if (A[i] == 0) {
                maximum = max(A[i], maximum);
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

        size_t sz = n;

        vector<double> prod(sz);
        for (size_t i = 0; i < sz; i++) {
            prod[i] = A[i];
        }

        double maximum = prod[0];
        for (size_t i = 1; i < sz; i++) {
            for (size_t t = 1; t <= i; t++) {
                auto j = i - t;
                prod[j] = prod[j] * A[i];
                maximum = (maximum < prod[j]) ? prod[j] : maximum;                
            }
        }

        return maximum;
    }
};

int main()
{
    int A[4] = {2, 3, -2, 4};

    Solution x;
    cout << x.maxProduct(A, 4) << '\n';

    int B[2] = {0, 2};
    cout << x.maxProduct(B, 2) << '\n';

    int C[3] = {-2, 2, -3};
    cout << x.maxProduct(C, 3) << '\n';

    int D[4] = {-3, 2, -2, 2};
    cout << x.maxProduct(D, 4) << '\n';

    int E[3] = {2, -1, 2};
    cout << x.maxProduct(E, 3) << '\n';

    return 0;
}