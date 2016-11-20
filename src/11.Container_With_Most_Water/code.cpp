#include "code.h"
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace Container_With_Most_Water
{
    int max_area(vector<int>& height)
    {
        auto int_max = numeric_limits<int>::max();
        if (height.size() > static_cast<size_t>(int_max))
        {
            throw runtime_error("cannot support vector that is longer than " + to_string(int_max));
        }
        auto low = 0;
        auto high = static_cast<int>(height.size()) - 1;
        auto a = 0;
        while (low < high)
        {
            auto current_area = (high - low) * min(height[low], height[high]);
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
        return a;
    }

    int Solution::maxArea(vector<int>& height)
    {
        return max_area(height);
    }
}
