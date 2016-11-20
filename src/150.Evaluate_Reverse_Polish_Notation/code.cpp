#include "code.h"
#include <stack>

using namespace std;

namespace Evaluate_Reverse_Polish_Notation
{
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

    int Solution::evalRPN(vector<string> &tokens) {
        return pre_eva(tokens);
    }
}