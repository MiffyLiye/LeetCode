#include "../include/catch.hpp"
#include "../../src/17.Letter_Combinations_of_a_Phone_Number/code.h"

using namespace std;
using namespace Letter_Combinations_of_a_Phone_Number;

namespace Letter_Combinations_of_a_Phone_Number
{
    template<typename T>
    bool vector_set_equals(vector<T> left, vector<T> right)
    {
        if (left.size() != right.size()) return false;

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for (size_t i = 0; i < left.size(); i++)
        {
            if (left[i] != right[i]) return false;
        }
        return true;
    }
}

TEST_CASE("Letter Combinations of a Phone Number",
          "[Letter Combinations of a Phone Number]")
{
    auto digits = string{"23"};
    Solution x;

    auto actual = x.letterCombinations(digits);

    auto expected = vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    REQUIRE(vector_set_equals(actual, expected));
}
