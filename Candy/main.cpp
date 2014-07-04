#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        return give_candy(ratings);
        }
private:
    int give_candy(vector<int>& ratings) {
        if (ratings.size() == 0) {
            return 0;
        }
        if (ratings.size() == 1) {
            return 1;
        }
        vector<int> candies(ratings.size());
        candies[0] = 1;
        size_t i {};
        for (i = 1; i < ratings.size(); i++) {
            if (ratings[i-1] < ratings[i]) {
                candies[i] = candies[i-1] + 1;
            }
            else {
                candies[i] = 1;
            }
        }

        i = ratings.size() - 2;
        while (true) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = (candies[i] > candies[i+1]) ? candies[i] : (candies[i+1] + 1);
            }
            if (i == 0) {
                break;
            }
            i--;
        }
        
        int total_candy = 0;
        for (auto x:candies) {
            total_candy += x;
        }
        return total_candy;
    }
};

int main()
{
    vector<int> ratings {2};
    Solution x;
    cout << x.candy(ratings) << '\n';

    return 0;
}