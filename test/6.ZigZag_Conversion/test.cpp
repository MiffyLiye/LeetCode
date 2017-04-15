#include "catch/catch.hpp"
#include "6.ZigZag_Conversion/code.h"

using namespace std;
using namespace ZigZag_Conversion;

TEST_CASE("PAYPALISHIRING -> PAHNAPLSIIGYIR",
          "[ZigZag Conversion]")
{
    auto s = string{"PAYPALISHIRING"};
    auto nRows = 3;
    Solution x;

    auto actual = x.convert(s, nRows);

    auto expected = string{"PAHNAPLSIIGYIR"};
    REQUIRE(actual == expected);
}
