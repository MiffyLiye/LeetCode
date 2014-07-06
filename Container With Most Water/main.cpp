#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        return max_area(height);
    }
private:
    int max_area(vector<int>& height) {
        size_t low = 0;
        size_t high = height.size() - 1;
        int a = 0;
        while (low < high) {
            int current_area = (high - low) * min(height[low], height[high]);
            a = current_area > a ? current_area : a;
            if (height[low] < height[high]) {
                low++;
            }
            else {
                high--;
            }
        }
        return a;
    }
};

int main()
{
    vector<int> height {1, 3, 5, 7, 11, 13, 17, 19};
    Solution x;
    cout << x.maxArea(height) << endl;
    height = {1, 1};
    cout << x.maxArea(height) << endl;
    return 0;
}