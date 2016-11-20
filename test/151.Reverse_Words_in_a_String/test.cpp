#include "../include/catch.hpp"
#include "../../src/151.Reverse_Words_in_a_String/code.h"

using namespace std;
using namespace Reverse_Words_in_a_String;

TEST_CASE("Reverse Words in a String","[Reverse Words in a String]")
{
    auto s = string{"the sky is blue"};
    Solution x;

    x.reverseWords(s);

    REQUIRE(s == string{"blue is sky the"});
}

