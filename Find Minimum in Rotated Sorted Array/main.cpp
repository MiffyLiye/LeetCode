#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        return find_min(num);
    }
private:
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
};

int main()
{
    Solution x;

    vector<int> num {0,1,2,3,4,5,6,7};
    cout << x.findMin(num) << '\n';

    num = {3,4,5,6,7,0,1,2};
    cout << x.findMin(num) << '\n';

    return 0;
}