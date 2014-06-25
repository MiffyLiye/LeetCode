#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        return nRows > 1 ? zig_zag_convert(s, nRows) : s;
    }
private:
    string zig_zag_convert(string& s, int n) {
        string t(s.size(), '\0');
        size_t c = s.size() / (2*n - 2);
        int remain = s.size() % (2*n - 2);
        if (remain == 0) {
            for (size_t i = 0; i < s.size(); i++) {
                size_t x = i / (2*n - 2);
                int y = i % (2*n - 2);
                if (y ==0) {
                    t[x] = s[i];
                }
                else if ( y < n-1) {
                    t[c + 2*(y-1)*c + 2*x] = s[i];
                }
                else if (y == n-1) {
                    t[c + 2*(n-2)*c + x] = s[i];
                }
                else {
                    auto e_y = 2*n - 2 - y;
                    t[c + 2*(e_y-1)*c + 2*x + 1] = s[i];
                }
            }
        }
        else if (remain < n) {
            for (size_t i = 0; i < s.size(); i++) {
                size_t x = i / (2*n - 2);
                int y = i % (2*n - 2);
                if (y ==0) {
                    t[x] = s[i];
                }
                else if (y < n-1) {
                    if ( y < remain) {
                        t[(c+1) + (y-1)*(2*c + 1) + 2*x] = s[i];
                    }
                    else {
                        t[(c+1) + (remain-1)*(2*c + 1) + (y-remain)*(2*c) + 2*x] = s[i];
                    }
                }
                else if (y == n-1) {
                    t[(c+1) + (remain-1)*(2*c + 1) + (y-remain)*(2*c) + x] = s[i];
                }
                else {
                    auto e_y = 2*n - 2 - y;
                    if (e_y < remain) {
                        t[(c+1) + (e_y-1)*(2*c + 1) + 2*x + 1] = s[i];
                    }
                    else {
                        t[(c+1) + (remain-1)*(2*c + 1) + (e_y - remain)*(2*c) + 2*x + 1] = s[i];
                    }
                }
            }
        }
        else if (remain == n) {
            for (size_t i = 0; i < s.size(); i++) {
                size_t x = i / (2*n - 2);
                int y = i % (2*n - 2);
                if (y ==0) {
                    t[x] = s[i];
                }
                else if ( y < n-1) {
                    t[(c+1) + (y-1)*(2*c + 1) + 2*x] = s[i];
                }
                else if (y == n-1) {
                    t[(c+1) + 2*(n-2)*c + (y-1) + x] = s[i];
                }
                else {
                    auto e_y = 2*n - 2 - y;
                    t[(c+1) + (e_y-1)*(2*c+1) + 2*x + 1] = s[i];
                }
            }
        }
        else {
            auto e_remain = 2*n - 1 - remain;
            for (size_t i = 0; i < s.size(); i++) {
                size_t x = i / (2*n - 2);
                int y = i % (2*n - 2);
                if (y ==0) {
                    t[x] = s[i];
                }
                else if (y < n-1) {
                    if ( y < e_remain) {
                        t[(c+1) + (y-1)*(2*c + 1) + 2*x] = s[i];
                    }
                    else {
                        t[(c+1) + (e_remain-1)*(2*c + 1) + (y-e_remain)*(2*c + 2) + 2*x] = s[i];
                    }
                }
                else if (y == n-1) {
                    t[(c+1) + (e_remain-1)*(2*c + 1) + (y-e_remain)*(2*c + 2) + x] = s[i];
                }
                else {
                    auto e_y = 2*n - 2 - y;
                    if (e_y < e_remain) {
                        t[(c+1) + (e_y-1)*(2*c + 1) + 2*x + 1] = s[i];
                    }
                    else {
                        t[(c+1) + (e_remain-1)*(2*c + 1) + (e_y - e_remain)*(2*c + 2) + 2*x + 1] = s[i];
                    }
                }
            }
        }
        return t;
    }
};

int main()
{
    Solution x;
    string s {"PAYPALISHIRING"};
    string t {"PAHNAPLSIIGYIR"};
    auto r = x.convert(s, 3);
    cout << s << '\n';
    cout << r << '\n';
    if (r == t) {
        cout << t << '\n';
    }

    return 0;
}