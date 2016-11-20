#include "code.h"
#include <vector>
#include <algorithm>

using namespace std;

namespace Longest_Palindromic_Substring
{
    string longest_palindrome(string& s)
    {
        if (s.size() == 0)
        {
            return s;
        }
        string st(2 * s.size() + 2, '\0');
        for (size_t i = 0; i < s.size(); i++)
        {
            st[2 * i + 2] = s[i];
        }
        vector<size_t> p(st.size());
        fill(p.begin(), p.end(), 0);
        p[1] = 0;
        size_t id = 1;
        size_t mx = id + p[id];
        for (size_t i = 2; i < st.size(); i++)
        {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 0;
            while (i + p[i] + 1 < st.size() && st[i + p[i] + 1] == st[i - p[i] - 1])
            {
                p[i]++;
            }
            if (i + p[i] > mx)
            {
                id = i;
                mx = id + p[id];
            }
        }
        id = 0;
        for (size_t i = 0; i < st.size(); i++)
        {
            if (p[i] > p[id])
            {
                id = i;
            }
        }

        size_t position = (id - p[id] + 1) / 2 - 1;
        size_t n = p[id];

        return s.substr(position, n);
    }

    string Solution::longestPalindrome(string s)
    {
        return longest_palindrome(s);
    }
}
