#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        return three_sum(num);
    }
private:
    vector<vector<int> > three_sum(vector<int> num) {
        sort(num.begin(), num.end());

        vector<vector<int>> result {};

        for (size_t i = 0; i < num.size(); i++) {
            if (i >= 1 && num[i-1] == num[i]) {
                continue;
            }
            size_t j = i + 1;
            size_t k = num.size() - 1;
            while (j < k) {
                if (j-1 >= i+1 && num[j-1] == num[j]) {
                    j++;
                    continue;
                }
                if (k+1 <= num.size()-1&& num[k] == num[k+1]) {
                    k--;
                    continue;
                }
                auto sum = num[i] + num[j] + num[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    result.push_back({num[i], num[j], num[k]});
                    j++;
                    k--;
                }
            }
        }    
        return result;
    }
};

int main()
{
    vector<int> num {-1, 0, 1, 2, -1, -4};
    Solution x;
    auto z = x.threeSum(num);
    for (auto v:z) {
        for (auto u:v) {
            cout << u << '\t';
        }
        cout << '\n';
    }

    return 0;
}