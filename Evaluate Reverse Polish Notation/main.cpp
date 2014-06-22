#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        return pre_eva(tokens);
    }
private:
    char input_type(const string& s) {
        if (s == "+") {
            return '+';
        }
        else if (s == "-") {
            return '-';
        }
        else if (s == "*") {
            return '*';
        }
        else if (s == "/") {
            return '/';
        }
        else {
            return '0';
        }
    }

    int pre_eva(vector<string>& tokens) {
        stack<int> s {};
        for (auto x : tokens) {
            if (input_type(x) == '0') {
                s.push(stoi(x));
            }
            else {
                auto t_2 = s.top();
                s.pop();
                auto t_1 = s.top();
                s.pop();
                switch(input_type(x)) {
                case '+':
                    t_1 += t_2;
                    break;
                case '-':
                    t_1 -= t_2;
                    break;
                case '*':
                    t_1 *= t_2;
                    break;
                case '/':
                    t_1 /= t_2;
                    break;
                }
                s.push(t_1);
            }
        }
        return s.top();
    }
};

int main()
{
    vector<string> tokens {"2", "1", "+", "3", "*"};
    Solution x;
    cout << x.evalRPN(tokens) << '\n';

    tokens.assign({"4", "13", "5", "/", "+"});
    cout << x.evalRPN(tokens) << '\n';

    return 0;
}
