#include<iostream>
#include<limits>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        return single_number(A, n);
    }
private:
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

    int single_number(int a[], int n) {
        vector<char> record (numeric_limits<int>::digits + 1);
        for (int i = 0; i < n; i++) {
            apply(a[i], record);
        }
        return extract(record);
    }
};

int main()
{
    int a[] = {1,1,1,2};
    Solution x;
    cout << x.singleNumber(a, 4) << endl;
    
    return 0;
}