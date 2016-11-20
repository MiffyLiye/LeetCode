#include "code.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace ZigZag_Conversion
{
    string zig_zag_convert(string& s, int n)
    {
        auto int_max = numeric_limits<int>::max();
        if (s.size() > static_cast<size_t>(int_max))
        {
            throw runtime_error("cannot support string that is longer than " + to_string(int_max));
        }

        if (n <= 1) return s;

        string t(s.size(), '\0');
        auto c = static_cast<int>(s.size()) / (2 * n - 2);
        auto remain = static_cast<int>(s.size()) % (2 * n - 2);
        if (remain == 0)
        {
            for (auto i = 0; i < static_cast<int>(s.size()); i++)
            {
                auto x = i / (2 * n - 2);
                auto y = i % (2 * n - 2);
                if (y == 0)
                {
                    t[x] = s[i];
                }
                else if (y < n - 1)
                {
                    t[c + 2 * (y - 1) * c + 2 * x] = s[i];
                }
                else if (y == n - 1)
                {
                    t[c + 2 * (n - 2) * c + x] = s[i];
                }
                else
                {
                    auto e_y = 2 * n - 2 - y;
                    t[c + 2 * (e_y - 1) * c + 2 * x + 1] = s[i];
                }
            }
        }
        else if (remain < n)
        {
            for (auto i = 0; i < static_cast<int>(s.size()); i++)
            {
                auto x = i / (2 * n - 2);
                auto y = i % (2 * n - 2);
                if (y == 0)
                {
                    t[x] = s[i];
                }
                else if (y < n - 1)
                {
                    if (y < remain)
                    {
                        t[(c + 1) + (y - 1) * (2 * c + 1) + 2 * x] = s[i];
                    }
                    else
                    {
                        t[(c + 1) + (remain - 1) * (2 * c + 1) + (y - remain) * (2 * c) + 2 * x] = s[i];
                    }
                }
                else if (y == n - 1)
                {
                    t[(c + 1) + (remain - 1) * (2 * c + 1) + (y - remain) * (2 * c) + x] = s[i];
                }
                else
                {
                    auto e_y = 2 * n - 2 - y;
                    if (e_y < remain)
                    {
                        t[(c + 1) + (e_y - 1) * (2 * c + 1) + 2 * x + 1] = s[i];
                    }
                    else
                    {
                        t[(c + 1) + (remain - 1) * (2 * c + 1) + (e_y - remain) * (2 * c) + 2 * x + 1] = s[i];
                    }
                }
            }
        }
        else if (remain == n)
        {
            for (auto i = 0; i < static_cast<int>(s.size()); i++)
            {
                auto x = i / (2 * n - 2);
                auto y = i % (2 * n - 2);
                if (y == 0)
                {
                    t[x] = s[i];
                }
                else if (y < n - 1)
                {
                    t[(c + 1) + (y - 1) * (2 * c + 1) + 2 * x] = s[i];
                }
                else if (y == n - 1)
                {
                    t[(c + 1) + 2 * (n - 2) * c + (y - 1) + x] = s[i];
                }
                else
                {
                    auto e_y = 2 * n - 2 - y;
                    t[(c + 1) + (e_y - 1) * (2 * c + 1) + 2 * x + 1] = s[i];
                }
            }
        }
        else
        {
            auto e_remain = 2 * n - 1 - remain;
            for (auto i = 0; i < static_cast<int>(s.size()); i++)
            {
                auto x = i / (2 * n - 2);
                auto y = i % (2 * n - 2);
                if (y == 0)
                {
                    t[x] = s[i];
                }
                else if (y < n - 1)
                {
                    if (y < e_remain)
                    {
                        t[(c + 1) + (y - 1) * (2 * c + 1) + 2 * x] = s[i];
                    }
                    else
                    {
                        t[(c + 1) + (e_remain - 1) * (2 * c + 1) + (y - e_remain) * (2 * c + 2) + 2 * x] = s[i];
                    }
                }
                else if (y == n - 1)
                {
                    t[(c + 1) + (e_remain - 1) * (2 * c + 1) + (y - e_remain) * (2 * c + 2) + x] = s[i];
                }
                else
                {
                    auto e_y = 2 * n - 2 - y;
                    if (e_y < e_remain)
                    {
                        t[(c + 1) + (e_y - 1) * (2 * c + 1) + 2 * x + 1] = s[i];
                    }
                    else
                    {
                        t[(c + 1) + (e_remain - 1) * (2 * c + 1) + (e_y - e_remain) * (2 * c + 2) + 2 * x + 1] = s[i];
                    }
                }
            }
        }
        return t;
    }

    string Solution::convert(string s, int nRows)
    {
        return zig_zag_convert(s, nRows);
    }
}
