#include<iostream>
#include<limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        return reverse_safe(x);
    }
private:
    int reverse_unsafe(int x) {
        bool is_negative = x < 0 ? true : false;
        x = is_negative ? -x : x;
        int rx {0};
        while (x != 0) {
            rx = rx*10 + x%10;
            x /= 10;
        }
        return is_negative ? -rx : rx;
    }

    // requires positive x and y
    int safe_add(int x, int y) {
        int sum = x + y;
        return sum < 0 ? -1 : sum;
    }

    // requires positive x
    int safe_multiply_10(int x) {
        const int w {numeric_limits<int>::digits + 1};
        return (x < (1 << (w-3))) ? safe_add(x * 8, x * 2) : -1;
    }

    int reverse_safe(int x) {
        bool is_negative = x < 0 ? true : false;
        x = is_negative ? -x : x;
        int rx {0};
        while (x != 0) {
            rx = safe_multiply_10(rx);
            if (rx == -1) {
                return 0;
            }
            rx = safe_add(rx, x%10);
            if (rx == -1) {
                return 0;
            }
            x /= 10;
        }
        return is_negative ? -rx : rx;
    }
};

int main()
{
    Solution x;
    cout << x.reverse(123) << endl;
    cout << x.reverse(-123) << endl;
    cout << x.reverse(numeric_limits<int>::max()) << endl;

    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;

    cout << numeric_limits<int>::digits << endl;
    
    return 0;
}