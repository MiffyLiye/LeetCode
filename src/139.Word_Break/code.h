#pragma once

#include <string>
#include <unordered_set>

namespace Word_Break
{
    class Solution{
    public:
        bool wordBreak(std::string s, std::unordered_set<std::string> &dict);
    };
}


