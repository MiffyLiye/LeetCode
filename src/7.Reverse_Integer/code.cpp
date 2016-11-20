#include "code.h"
#include <limits>

using namespace std;

namespace Reverse_Integer
{
    int reverse_unsafe(int x)
    {
        auto is_negative = x < 0;
        x = is_negative ? -x : x;
        int rx{0};
        while (x != 0)
        {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return is_negative ? -rx : rx;
    }

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

    int reverse_safe(int x)
    {
        auto is_negative = x < 0;
        x = is_negative ? -x : x;
        int rx{0};
        while (x != 0)
        {
            rx = safe_multiply_10(rx);
            if (rx == -1)
            {
                return 0;
            }
            rx = safe_add(rx, x % 10);
            if (rx == -1)
            {
                return 0;
            }
            x /= 10;
        }
        return is_negative ? -rx : rx;
    }

    int Solution::reverse(int x)
    {
        return reverse_safe(x);
    }
}
