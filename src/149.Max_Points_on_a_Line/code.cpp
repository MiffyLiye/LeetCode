#include "code.h"
#include <map>
#include <set>
#include <limits>
#include <string>
#include <stdexcept>

using namespace std;

namespace Max_Points_on_a_Line
{
    int gcd(int a, int b)
    {
        if (a != 0)
        {
            return gcd(b % a, a);
        }
        else
        {
            if (b != 0)
            {
                return b;
            }
            else
            {
                return 1;
            }
        }
    }

    int gcd(int a, int b, int c)
    {
        return gcd(gcd(a, b), c);
    }

    struct Line
    {
        int a_;
        int b_;
        int c_;

        Line() : a_(0), b_(0), c_(0) {}

        Line(Point a, Point b) : a_{a.y - b.y}, b_{-a.x + b.x}, c_{-a.x * (a.y - b.y) + a.y * (a.x - b.x)}
        {
            auto t = gcd(a_, b_, c_);
            t = t < 0 ? -t : t;
            if ((a_ < 0) || (a_ == 0 && b_ < 0) || (a_ == 0 && b_ == 0 && c_ < 0))
            {
                t = -t;
            }
            a_ /= t;
            b_ /= t;
            c_ /= t;
        }
    };

    struct Less
    {
        bool operator()(const Point& a, const Point& b) const
        {
            if (a.x != b.x)
            {
                return a.x < b.x;
            }
            else
            {
                return a.y < b.y;
            }
        }

        bool operator()(const Line& x, const Line& y) const
        {
            if (x.a_ != y.a_)
            {
                return x.a_ < y.a_;
            }
            else if (x.b_ != y.b_)
            {
                return x.b_ < y.b_;
            }
            else
            {
                return x.c_ < y.c_;
            }
        }
    };

    int max_points_ordered(vector<Point>& points)
    {
        auto int_max = numeric_limits<unsigned int>::max() / 2;
        if (points.size() > int_max)
        {
            throw runtime_error("cannot support points number that is longer than " + to_string(int_max));
        }

        map<Line, set<size_t>, Less> m;
        for (auto x = 0u; x != points.size(); x++)
        {
            for (auto y = x + 1; y != points.size(); y++)
            {
                Line line(points[x], points[y]);
                if (m.find(line) == m.end())
                {
                    m.insert({line, set<size_t>{}});
                }
                m.at(line).insert(x);
                m.at(line).insert(y);
            }
        }

        Line singular_line{};
        if (m.find(singular_line) != m.end() && m.size() > 1)
        {
            m.at(singular_line).clear();
        }

        Line opt_line;
        size_t count = 0;
        for (auto& x:m)
        {
            if (x.second.size() > count)
            {
                opt_line = x.first;
                count = x.second.size();
            }
        }
        return static_cast<int>(count);
    }

    int Solution::maxPoints(vector<Point>& points)
    {
        if (points.size() >= 2)
        {
            return max_points_ordered(points);
        }
        else if (points.size() == 1)
        {
            return static_cast<int>(points.size());
        }
        else
        {
            return 0;
        }
    }
}