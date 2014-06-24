#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        auto index = two_sum(numbers, target);
        for (auto& x:index) {
            x += 1;
        }
        return index;
    }
private:
    vector<int> get_index(vector<int>& numbers, int x, int y) {
        vector<int> index {0, 0};
        vector<bool> is_done {false, false};
        for (size_t i = 0; i < numbers.size() && (!is_done[0] || !is_done[1]); i++) {
            if (!is_done[0] && numbers[i] == x) {
                index[0] = i;
                is_done[0] = true;
                continue;
            }
            else if (!is_done[1] && numbers[i] == y) {
                index[1] = i;
                is_done[1]= true;
                continue;
            }
        }
        if (!is_done[0] || !is_done[1]) {
            index[0] = 0;
            index[1] = 0;
        }
        else {
            sort(index.begin(), index.end());
        }
        return index;
    }

    vector<int> two_sum(vector<int>& numbers, int target) {
        set<int> s;
        vector<int> index {0, 0};
        for (auto x:numbers) {
            s.insert(x);
        }
        for (auto x = s.begin(); x != s.end(); x++) {
            if (*x * 2 <= target) {
                if (s.find(target - *x) != s.end()) {
                    index = get_index(numbers, *x, target - *x);
                    if (index[0] == index[1]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                break;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> numbers {2, 7, 11, 15};
    int target {9};

    Solution x;
    auto index = x.twoSum(numbers, target);

    for (auto x:index) {
        cout << x << endl;
    }

    return 0;
}
