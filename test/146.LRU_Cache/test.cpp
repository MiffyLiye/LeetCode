#include "catch/catch.hpp"
#include "146.LRU_Cache/code.hpp"

using namespace std;
using namespace LRU_Cache;

TEST_CASE("LRU_Cache read", "[LRU_Cache]")
{
    LRUCache x(2);

    x.set(2, 1);

    REQUIRE(x.get(2) == 1);

    x.set(2, 2);

    REQUIRE(x.get(2) == 2);
}

TEST_CASE("LRU_Cache invalidate least recently used", "[LRU_Cache]")
{
    LRUCache x(2);

    x.set(1, 1);
    x.set(2, 2);
    x.set(3, 3);

    REQUIRE(x.get(1) == -1);

    x.get(2);
    x.set(4, 4);

    REQUIRE(x.get(3) == -1);
}
