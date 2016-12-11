#include "code.h"
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace Container_With_Most_Water
{
    int max_area(vector<int>& height)
    {
        auto int_max = numeric_limits<unsigned int>::max() / 2;
        if (height.size() > int_max)
        {
            throw runtime_error("cannot support vector that is longer than " + to_string(int_max));
        }
        for (auto i : height)
        {
            if (i < 0)
            {
                throw runtime_error("cannot support height that is smaller than 0");
            }
        }
        size_t low = 0u;
        size_t high = height.size() - 1;
        size_t a = 0u;
        while (low < high)
        {
            auto current_area = (high - low) * min(static_cast<size_t>(height[low]), static_cast<size_t>(height[high]));
            a = current_area > a ? current_area : a;
            if (height[low] < height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return static_cast<int>(a);
    }

    int Solution::maxArea(vector<int>& height)
    {
        return max_area(height);
    }
}
