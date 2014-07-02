#include<iostream>
#include<limits>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return is_palindrome(x);
    }
    Solution () : head_ {1} {
        for (int i = 0; i < numeric_limits<int>::digits10; i++) {
            head_ *= 10;
        }
    }
private:
    int head_;

    bool is_palindrome(int x) {
        if (x < 0) {
            return false;
        }

        int head = head_;
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