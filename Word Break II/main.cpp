#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return word_break(s, dict);
    }
private:
    void reverse_string(string& s, size_t position, size_t n) {
        auto begin = position;
        auto end = position + n;
        while (begin + 1 < end) {
            auto t = s[begin];
            s[begin] = s[end-1];
            s[end-1] = t;
            begin++;
            end--;
        }
    }

    void reverse_in_place(string &s) {
        reverse_string(s, 0, s.size());
        size_t position = 0;
        size_t length = 0;
        while (position + length != s.size()) {
            if (s[position + length] == ' ') {
                if (length == 0) {
                    position++;
                    continue;
                }
                else {
                    reverse_string(s, position, length);
                    position += length;
                    length = 0;
                }
            }
            else {
                length++;
            }
        }
        if (length != 0) {
            reverse_string(s, position, length);
        }
        // reducing multiple spaces in string increases temporal complexity
    }

    // m[i][x] the possible start position that make the substring ends at i a word.
    vector<string> extract(string& s, vector<vector<size_t>>& m) {
        vector<string> vs {};
        vector<size_t> start {};
        if (m[s.size() - 1].empty()) {
            return vector<string>{};
        }
        else {
            for (size_t i = 0; i < m[s.size() - 1].size(); i++) {
                start.push_back(m[s.size() - 1][i]);
                vs.push_back(s.substr(m[s.size() - 1][i], s.size() - m[s.size() - 1][i]));
            }
        }
        size_t current {0};
        while (current != vs.size()) {
            if (start[current] == 0) {
                current++;
                continue;
            }
            else if (m[start[current] - 1].size() == 1) {
                vs[current].append(" ");
                vs[current].append(s.substr(m[start[current] - 1][0], start[current] - m[start[current] - 1][0]));
                start[current] = m[start[current] - 1][0];
            }
            else {
                for (size_t i = 1; i < m[start[current] - 1].size(); i++) {
                    vs.push_back(vs[current]);
                    vs[vs.size() - 1].append(" ");
                    vs[vs.size() - 1].append(s.substr(m[start[current] - 1][i], start[current] - m[start[current] - 1][i]));
                    start.push_back(m[start[current] - 1][i]);
                }
                vs[current].append(" ");
                vs[current].append(s.substr(m[start[current] - 1][0], start[current] - m[start[current] - 1][0]));
                start[current] = m[start[current] - 1][0];
            }
        }

        for (size_t i = 0; i < vs.size(); i++) {
            reverse_in_place(vs[i]);
        }

        return vs;
    }

    vector<string> word_break(string& s, unordered_set<string>& dict) {
        vector<vector<size_t>> m(s.size());
        for (size_t i = 0; i < s.size(); i++) {   
            m[i] =  (dict.find(s.substr(0, i+1)) != dict.end()) ? vector<size_t>{0} : vector<size_t>{};
            for (size_t j = 0; j < i; j++) {
                if (!m[j].empty() && dict.find(s.substr(j+1, i-j)) != dict.end()) {
                    m[i].push_back(j+1);
                }
            }
        }

        auto vs = extract(s, m);

        return vs;
    }
};

int main()
{
    string s {"catsanddog"};
    unordered_set<string> dict {"cat", "cats", "and", "sand", "dog"};

    Solution x;
    auto vs = x.wordBreak(s, dict);
    for (auto& z:vs) {
        cout << z << '\n';
    }

    return 0;
}
