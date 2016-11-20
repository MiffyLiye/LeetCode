#include "../include/catch.hpp"
#include "../../src/18.4Sum/code.h"

using namespace std;
using namespace Four_Sum;

namespace Four_Sum
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

    template<typename T>
    bool vector_set_contains(vector<vector<T>> set, vector<T> vec)
    {
        for (auto& v : set)
        {
            if (vector_set_equals(v, vec)) return true;
        }
        return false;
    }

    template<typename T>
    bool vector_vector_set_equals(vector<vector<T>> left, vector<vector<T>> right)
    {
        if (left.size() != right.size()) return false;
        for (auto& vec : left)
        {
            if (!vector_set_contains(right, vec)) return false;
        }
        return true;
    }
}

TEST_CASE("4Sum",
          "[4Sum]")
{
    auto num = vector<int>{1, 0, -1, 0, -2, 2};
    auto target = 0;
    Solution x;

    auto actual = x.fourSum(num, target);

    auto expected = vector<vector<int>>{
            {-1, 0,  0, 1},
            {-2, -1, 1, 2},
            {-2, 0,  0, 2}
    };
    REQUIRE(vector_vector_set_equals(actual, expected));
}
