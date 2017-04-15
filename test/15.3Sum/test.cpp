#include "catch/catch.hpp"
#include "15.3Sum/code.h"

using namespace std;
using namespace Three_Sum;

namespace Three_Sum
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

TEST_CASE("3Sum",
          "[3Sum]")
{
    auto num = vector<int>{-1, 0, 1, 2, -1, -4};
    Solution x;

    auto actual = x.threeSum(num);

    auto expected = vector<vector<int>>{
            {-1, 0,  1},
            {-1, -1, 2}
    };
    REQUIRE(vector_vector_set_equals(actual, expected));
}
