#ifndef MAX2TIMES_H
#define MAX2TIMES_H
#include <vector>
using namespace std;
namespace Max2Times {
class Solution
{
public:
    Solution() {}
    static int dominantIndex(vector<int>& nums)
    {
        if(nums.size() == 0)
            return -1;
        auto max = 0;
        auto index = -1;
        auto cmp = [&](int a, int b, int index){if(a<b)index++;return a>b?a:b;};
        for(auto item = nums.cbegin(); item != nums.cend(); item++)
        {
            if(max < *item)
            {
                max = *item;
                index = distance(nums.cbegin(), item);
            }
        }

        for(auto item = nums.cbegin(); item != nums.cend(); item++)
        {
            if(max == *item)
                continue;
            if(max < 2*(*item))
                return -1;
        }

        return index;
    }
};
}
#endif // MAX2TIMES_H
