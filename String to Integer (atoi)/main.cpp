#include<iostream>
#include<limits>
#include<cctype>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        return stoi(str);
    }

private:
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

    int digit2i(char c) {
        return c - '0';
    }

    int stoi(const char* str) {
        while (isspace(*str)) {
            str++;
        }
        bool started {false};
        bool is_negative {false};

        int result {0};

        for (; *str != '\0'; str++) {
            if (*str == '+') {
                if (!started) {
                    started = true;
                    is_negative = false;
                }
                else {
                    return 0;
                }
            }
            else if (*str == '-') {
                if (!started) {
                    started = true;
                    is_negative = true;
                }
                else {
                    return 0;
                }
            }
            else if (isdigit(*str)) {
                if (!started) {
                    started = true;
                    is_negative = false;
                }
                result = safe_multiply_10(result);
                if (result == -1) {
                    return is_negative ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }
                result = safe_add(result, digit2i(*str));
                if (result == -1) {
                    return is_negative ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }
            }
            else {
                break;
            }
        }
        return is_negative ? -result : result;
    }
};

int main()
{
    Solution x;

    cout << x.atoi("  -214748364xyz") << endl;

    cout << x.atoi(" 2147483647777") << endl;

    cout << x.atoi("   xyz214748364") << endl;

    return 0;
}