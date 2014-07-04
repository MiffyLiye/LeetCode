#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        return word_break(s, dict);
    }
private:
    bool word_break(string s, unordered_set<string>& dict) {
        vector<bool> is_sentence(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            is_sentence[i] = false;
            for (size_t j = (i > 0) ? (i-1) : 0; j > 0; j--) {
                if (is_sentence[j]) {
                    if (dict.find(s.substr(j+1, i-j)) != dict.end()) {
                        is_sentence[i] = true;
                        break;
                    }
                }
            }
            if (!is_sentence[i] && is_sentence[0] && dict.find(s.substr(1, i)) != dict.end()) {
                is_sentence[i] = true;
            }
            if (!is_sentence[i] && dict.find(s.substr(0, i+1)) != dict.end()) {
                is_sentence[i] = true;
            }
        }
        return is_sentence[s.size() - 1];
    }
};

int main()
{
    string s {"leetcode"};
    unordered_set<string> dict {};
    dict.insert("leet");
    dict.insert("code");

    Solution x;
    cout << (x.wordBreak(s, dict) ? "is" : "is not") << endl;

    cout << s.substr(0,4) << endl;
    cout << s.substr(1,3) << endl;
    return 0;
}