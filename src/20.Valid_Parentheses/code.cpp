#include "code.h"
#include <stack>
#include <map>

using namespace std;

namespace Valid_Parentheses
{
    const map<char, char> right_left_parentheses_map =
            {
                    {')', '('},
                    {']', '['},
                    {'}', '{'}
            };

    bool is_right_parenthesis(char c)
    {
        return right_left_parentheses_map.find(c) != right_left_parentheses_map.end();
    }

    char get_left_part(char c)
    {
        return right_left_parentheses_map.find(c)->second;
    }

    bool Solution::isValid(std::string s)
    {
        auto left_parentheses = stack<char>();
        for (auto c : s)
        {
            if (!is_right_parenthesis(c))
            {
                left_parentheses.push(c);
            }
            else
            {
                if (left_parentheses.empty()){
                    return false;
                }
                auto stored_parenthesis = left_parentheses.top();
                left_parentheses.pop();
                auto expected_parenthesis = get_left_part(c);
                if (stored_parenthesis != expected_parenthesis)
                {
                    return false;
                }
            }
        }

        return left_parentheses.empty();
    }
}