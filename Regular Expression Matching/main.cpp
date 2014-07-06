#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return regex_match(s, p, '\0');
    }
private:
    bool regex_match(const char* s, const char* p, char c) {
        if (s[0] == '\0') {
            if (p[0] == '\0') {
                return true;
            }
            else if (p[0] == '*') {
                return regex_match(s, p+1, '\0');
            }
            else if (p[1] == '*') {
                return regex_match(s, p+2, '\0');
            }
            else {
                return false;
            }
        }
        if (p[0] == '\0') {
            return false;
        }

        if (p[0] != '*') {
            return (p[1] == '*' && regex_match(s, p+2, '\0')) || (p[0] == '.' && regex_match(s+1, p+1, '\0')) || (s[0] == p[0] && regex_match(s+1, p+1, s[0]));
        }
        else {
            return (c == '\0' && regex_match(s+1, p, c)) || (s[0] == c && regex_match(s+1, p, c)) || regex_match(s, p+1, '\0');
        }
    }
};

int main()
{
    Solution x;

    cout << (x.isMatch("aa", "a") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("aa", "aa") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("aaa", "aa") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("aa", "a*") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("aa", ".*") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("ab", ".*") ? "matched\n" : "not matched\n");
    cout << (x.isMatch("aab", "c*a*b") ? "matched\n" : "not matched\n");

    return 0;
}
