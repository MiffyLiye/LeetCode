#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        return int_to_roman(num);
    }
private:
    string digit_to_roman(int n) {
        switch (n) {
            case 1:
            return "I";
            case 5:
            return "V";
            case 10:
            return "X";
            case 50:
            return "L";
            case 100:
            return "C";
            case 500:
            return "D";
            case 1000:
            return "M";
            default:
            return "";
        }
    }

    string int_to_roman(int num) {
        string s {};
        int current {};
        current = num / 1000;
        for (auto i = 0; i < current; i++) {
            s.append("M");
        }

        for (int base = 100; base > 0; base = base/10) {
            num %= 10 * base;
            current = num / base;
            if (current >= 5) {
                if (current == 9) {
                    s.append(digit_to_roman(base));
                    s.append(digit_to_roman(10*base));
                }
                else {
                    s.append(digit_to_roman(5*base));
                    current = current - 5;
                    for (auto i = 0; i < current; i++) {
                        s.append(digit_to_roman(base));
                    }
                }
            }
            else {
                if (current == 4) {
                    s.append(digit_to_roman(base));
                    s.append(digit_to_roman(5*base));
                }
                else {
                    for (auto i = 0; i < current; i++) {
                        s.append(digit_to_roman(base));
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    int i {1912};
    Solution x;
    cout << x.intToRoman(i) << endl;

    return 0;
}