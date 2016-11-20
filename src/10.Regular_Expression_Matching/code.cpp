#include "code.h"
using namespace std;

namespace Regular_Expression_Matching
{
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

    bool Solution::isMatch(string s, string p) {
        return regex_match(s.c_str(), p.c_str(), '\0');
    }
}
