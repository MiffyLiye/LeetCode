#include "code.h"
#include <vector>

using namespace std;

namespace Longest_Common_Prefix
{
    string longest_common_prefix(vector <string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        else if (strs.size() == 1)
        {
            return strs[0];
        }

        size_t position{0};
        while (true)
        {
            for (size_t i = 0; i < strs.size(); i++)
            {
                if (strs[i].size() < position + 1)
                {
                    return strs[0].substr(0, position);
                }
                else if (i == 0)
                {
                    continue;
                }

                if (strs[i][position] != strs[0][position])
                {
                    return strs[0].substr(0, position);
                }
            }
            position++;
        }
    }

    string Solution::longestCommonPrefix(vector <string>& strs)
    {
        return longest_common_prefix(strs);
    }
}
