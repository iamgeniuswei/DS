#ifndef CENTRALINDEXOFARRAY_H
#define CENTRALINDEXOFARRAY_H
#include <vector>
using namespace std;
namespace CentralIndexOfArray {
class Solution
{
public:
    Solution() {}
    static int pivotIndex(vector<int>& nums)
    {
        if(nums.size() > 10000 || nums.size() < 1)
            return -1;
        int sum = 0;
        int left_sum = 0;
        int right_sum = 0;
        for (auto item = nums.cbegin(); item != nums.cend();item++)
        {
            sum += *item;
        }
        int index = 0;
        while (index < nums.size())
        {
            if(index != 0)
                left_sum += nums[index - 1];
            right_sum = sum - left_sum - nums[index];
            if(left_sum == right_sum)
                return index;
            index++;
        }
        return -1;
    }
};
}


#endif // CENTRALINDEXOFARRAY_H
