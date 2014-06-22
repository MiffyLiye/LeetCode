#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse_words(s);
    }
private:
    void reverse_words(string& s) {
        s = constructWords(splitWords(s));
    }
    stack<string> splitWords(const string& s) {
        stack<string> split {};
        size_t position = 0;
        size_t length = 0;
        while (position + length != s.size()) {
            if (s[position + length] == ' ') {
                if (length == 0) {
                    position++;
                    continue;
                }
                else {
                    split.push(s.substr(position, length));
                    position += length;
                    length = 0;
                }
            }
            else {
                length++;
            }
        }
        if (length != 0) {
            split.push(s.substr(position, length));
        }
        return split;
    }

    string constructWords(stack<string>&& split) {
        string s {};
        while (split.size()) {
            switch (split.size()) {
                case 1:
                    s.append(split.top());
                    split.pop();
                    break;
                default:
                    s.append(split.top()).append(" ");
                    split.pop();
            }
        }
        return s;
    }

    void reverse_in_place(string &s) {
        reverse_string(s, 0, s.size());
        size_t position = 0;
        size_t length = 0;
        while (position + length != s.size()) {
            if (s[position + length] == ' ') {
                if (length == 0) {
                    position++;
                    continue;
                }
                else {
                    reverse_string(s, position, length);
                    position += length;
                    length = 0;
                }
            }
            else {
                length++;
            }
        }
        if (length != 0) {
            reverse_string(s, position, length);
        }
        // reducing multiple spaces in string increases temporal complexity
    }

    void reverse_string(string& s, size_t position, size_t n) {
        auto begin = position;
        auto end = position + n;
        while (begin + 1 < end) {
            auto t = s[begin];
            s[begin] = s[end-1];
            s[end-1] = t;
            begin++;
            end--;
        }
    }
};

int main()
{
    string s {"the sky is blue"};
    cout << s << '\n';

    Solution x;
    x.reverseWords(s);

    cout << s << '\n';

    return 0;
}