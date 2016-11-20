#include "code.h"
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

namespace Longest_Substring_Without_Repeating_Characters
{
    int length_of_longest_substring_ordered(const string& s)
    {
        int int_max = numeric_limits<int>::max();
        if (s.size() > static_cast<size_t>(int_max))
        {
            throw runtime_error("cannot support string that is longer than " + to_string(int_max));
        }

        auto max_count = 0;
        auto new_start = 0;
        if (s.size() != 0)
        {
            map<char, int> last_position{};
            for (auto p = 0; p < static_cast<int>(s.size()); p++)
            {
                if (last_position.count(s[p]) == 0)
                {
                    last_position.insert({s[p], p});
                    max_count = max(p - new_start + 1, max_count);
                }
                else
                {
                    new_start = max(last_position[s[p]] + 1, new_start);
                    max_count = max(min(p - last_position[s[p]], p - new_start + 1), max_count);
                    last_position[s[p]] = p;
                }
            }

            return max_count;
        }
        else
        {
            return 0;
        }
    }

    int length_of_longest_substring_unordered(const string& s)
    {
        auto max_count = 0;
        auto new_start = 0;
        if (s.size() != 0)
        {
            unordered_map<char, int> last_position{};
            for (auto p = 0; p < static_cast<int>(s.size()); p++)
            {
                if (last_position.count(s[p]) == 0)
                {
                    last_position.insert({s[p], p});
                    max_count = max(p - new_start + 1, max_count);
                }
                else
                {
                    new_start = max(last_position[s[p]] + 1, new_start);
                    max_count = max(min(p - last_position[s[p]], p - new_start + 1), max_count);
                    last_position[s[p]] = p;
                }
            }

            return max_count;
        }
        else
        {
            return 0;
        }
    }

    int Solution::lengthOfLongestSubstring(std::string s)
    {
        return length_of_longest_substring_unordered(s);
    }
}
