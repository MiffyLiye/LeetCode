#include "code.h"
#include <vector>
using namespace std;

namespace Word_Break{

    bool word_break(string s, unordered_set<string>& dict) {
        vector<bool> is_sentence(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            is_sentence[i] = false;
            for (size_t j = (i > 0) ? (i-1) : 0; j > 0; j--) {
                if (is_sentence[j]) {
                    if (dict.find(s.substr(j+1, i-j)) != dict.end()) {
                        is_sentence[i] = true;
                        break;
                    }
                }
            }
            if (!is_sentence[i] && is_sentence[0] && dict.find(s.substr(1, i)) != dict.end()) {
                is_sentence[i] = true;
            }
            if (!is_sentence[i] && dict.find(s.substr(0, i+1)) != dict.end()) {
                is_sentence[i] = true;
            }
        }
        return is_sentence[s.size() - 1];
    }

    bool Solution::wordBreak(string s, unordered_set<string> &dict) {
        return word_break(s, dict);
    }
}