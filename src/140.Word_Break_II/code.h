#pragma once
#include <vector>
#include <string>
#include <unordered_set>

namespace Word_Break_II
{
    class Solution
    {
    public:
        std::vector<std::string> wordBreak(std::string s, std::unordered_set<std::string> &dict);
    };
}
