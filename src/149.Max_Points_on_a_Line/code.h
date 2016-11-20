#pragma once

#include <vector>

namespace Max_Points_on_a_Line
{
    struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
    };

    class Solution
    {
    public:
        int maxPoints(std::vector<Point> &points);
    };
}