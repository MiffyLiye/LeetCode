#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return length_of_longest_substring_unordered(s);
    }
private:
    int length_of_longest_substring_ordered(const string& s) {
        size_t max_count = 0;
        size_t new_start = 0;
        if (s.size() != 0) {
            map<char, size_t> last_position {};
            for (size_t p = 0; p < s.size(); p++) {
                if (last_position.count(s[p]) == 0) {
                    last_position.insert(pair<char, size_t>(s[p], p));
                    max_count = max(p - new_start + 1, max_count);
                }
                else {
                    new_start = max(last_position[s[p]] + 1, new_start);
                    max_count = max(min(p - last_position[s[p]], p - new_start + 1), max_count);
                    last_position[s[p]] = p;
                }
            }

            return max_count;
        }
        else {
            return 0;
        }
    }

    int length_of_longest_substring_unordered(const string& s) {
        size_t max_count = 0;
        size_t new_start = 0;
        if (s.size() != 0) {
            unordered_map<char, size_t> last_position {};
            for (size_t p = 0; p < s.size(); p++) {
                if (last_position.count(s[p]) == 0) {
                    last_position.insert(pair<char, size_t>(s[p], p));
                    max_count = max(p - new_start + 1, max_count);
                }
                else {
                    new_start = max(last_position[s[p]] + 1, new_start);
                    max_count = max(min(p - last_position[s[p]], p - new_start + 1), max_count);
                    last_position[s[p]] = p;
                }
            }

            return max_count;
        }
        else {
            return 0;
        }
    }

};

int main()
{
    string s {"abcabcbb"};
    Solution x;
    cout << x.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << x.lengthOfLongestSubstring("bbbbb") << endl;

    return 0;
}