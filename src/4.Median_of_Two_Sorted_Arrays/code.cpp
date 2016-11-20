#include "code.h"
#include <algorithm>

using namespace std;

namespace Median_of_Two_Sorted_Arrays
{
    int find_kth_sorted_arrays(int a[], int m, int b[], int n, int k)
    {
        if (m == 0)
        {
            return b[k - 1];
        }
        else if (n == 0)
        {
            return a[k - 1];
        }
        if (k == m + n)
        {
            return max(a[m - 1], b[n - 1]);
        }

        int i = m * (k - 1) / (m + n);
        int j = k - 1 - i;
        if (j >= n)
        {
            i += (j - (n - 1));
            j = n - 1;
        }

        if (a[i] <= b[j])
        {
            if (j == 0 || b[j - 1] <= a[i])
            {
                return a[i];
            }
        }
        if (b[j] <= a[i])
        {
            if (i == 0 || a[i - 1] <= b[j])
            {
                return b[j];
            }
        }

        if (a[i] <= b[j])
        {
            return find_kth_sorted_arrays(a + i + 1, m - i - 1, b, j, k - i - 1);
        }
        else
        {
            return find_kth_sorted_arrays(a, m, b + j + 1, n - j - 1, k - j - 1);
        }
    }

    double Solution::findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        double x{};
        if ((m + n) % 2 == 0)
        {
            int s = find_kth_sorted_arrays(A, m, B, n, (m + n) / 2 + 1);
            int t = find_kth_sorted_arrays(A, m, B, n, (m + n) / 2);
            x = static_cast<double>(s + t) / 2;
        }
        else
        {
            x = static_cast<double>(find_kth_sorted_arrays(A, m, B, n, (m + n + 1) / 2));
        }
        return x;
    }
}
