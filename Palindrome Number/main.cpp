#include<iostream>
#include<limits>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return is_palindrome(x);
    }
private:
    constexpr int pow(int base, int exp) {
        return exp > 0 ? base * pow(base, exp - 1) : 1;
    }

    int max_head() {
        static int head {pow(10, numeric_limits<int>::digits10)};
        return head;
    }

    bool is_palindrome(int x) {
        if (x < 0) {
            return false;
        }

        int head = max_head();
        int tail = 1;

        while (head > 1 && ((x / head) % 10) == 0) {
            head /= 10;
        }

        bool is {true};
        while (head > tail) {
            if (((x / head) % 10) != ((x / tail) % 10)) {
                is = false;
                break;
            }
            else {
                head /= 10;
                tail *= 10;
            }
        }
        return is;
    }
};

int main()
{
    Solution x;
    int a {2122222212};
    cout << (x.isPalindrome(a) ? a : 0) << endl;

    a = 12321;
    cout << (x.isPalindrome(a) ? a : 0) << endl;

    a = -2147447412;
    cout << (x.isPalindrome(a) ? a : 0) << endl;

    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<int>::digits10 << endl;

    return 0;
}