#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letter_combinations(digits);
    }
private:
    int char_to_digit(char c) {
        switch (c) {
            case 'a': case 'b': case 'c':
            return 2;
            case 'd': case 'e': case 'f':
            return 3;
            case 'g': case 'h': case 'i':
            return 4;
            case 'j': case 'k': case 'l':
            return 5;
            case 'm': case 'n': case 'o':
            return 6;
            case 'p': case 'q': case 'r': case 's':
            return 7;
            case 't': case 'u': case 'v':
            return 8;
            case 'w': case 'x': case 'y': case 'z':
            return 9;
            default:
            return 0;
        }
    }
    char first_char(int n) {
        switch (n) {
            case 2:
            return 'a';
            case 3:
            return 'd';
            case 4:
            return 'g';
            case 5:
            return 'j';
            case 6:
            return 'm';
            case 7:
            return 'p';
            case 8:
            return 't';
            case 9:
            return 'w';
            default:
            return '\0';
        }
    }

    int ctoi(char c) {
        return c - '0';
    }

    void next_string(string& s) {
        for (auto& c:s) {
            char t = c;
            if (char_to_digit(t+1) == char_to_digit(t)) {
                c = t+1;
                break;
            }
            else {
                c = first_char(char_to_digit(t));
            }
        }
    }
    vector<string> letter_combinations(string& digits) {
        string s{};
        s.resize(digits.size());
        for (size_t i = 0; i < digits.size(); i++) {
            s[i] = first_char(ctoi(digits[i]));
        }
        string first_string {s};

        vector<string> v {};
        v.push_back(s);
        next_string(s);

        while (s != first_string) {
            v.push_back(s);
            next_string(s);
        }
        return v;
    }
};

int main()
{
    Solution x;
    string digits {"23"};
    auto z = x.letterCombinations(digits);
    for (auto& s:z) {
        cout << s << endl;
    }

    return 0;
}