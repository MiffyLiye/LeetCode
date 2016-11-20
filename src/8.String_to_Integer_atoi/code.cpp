#include "code.h"
#include <limits>
#include <cctype>

using namespace std;

namespace String_to_Integer_atoi
{
    // requires positive x and y
    int safe_add(int x, int y)
    {
        auto sum = x + y;
        return sum < 0 ? -1 : sum;
    }

    // requires positive x
    int safe_multiply_10(int x)
    {
        const int w{numeric_limits<int>::digits + 1};
        return (x < (1 << (w - 3))) ? safe_add(x * 8, x * 2) : -1;
    }

    int digit2i(char c)
    {
        return c - '0';
    }

    int stoi(const char* str)
    {
        while (isspace(*str))
        {
            str++;
        }
        bool started{false};
        bool is_negative{false};

        int result{0};

        for (; *str != '\0'; str++)
        {
            if (*str == '+')
            {
                if (!started)
                {
                    started = true;
                    is_negative = false;
                }
                else
                {
                    return 0;
                }
            }
            else if (*str == '-')
            {
                if (!started)
                {
                    started = true;
                    is_negative = true;
                }
                else
                {
                    return 0;
                }
            }
            else if (isdigit(*str))
            {
                if (!started)
                {
                    started = true;
                    is_negative = false;
                }
                result = safe_multiply_10(result);
                int int_min = numeric_limits<int>::min();
                int int_max = numeric_limits<int>::max();
                if (result == -1)
                {
                    return is_negative ? int_min : int_max;
                }
                result = safe_add(result, digit2i(*str));
                if (result == -1)
                {
                    return is_negative ? int_min : int_max;
                }
            }
            else
            {
                break;
            }
        }
        return is_negative ? -result : result;
    }

    int Solution::atoi(string str)
    {
        return stoi(str.c_str());
    }
}
