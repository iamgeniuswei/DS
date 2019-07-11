#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "centralindexofarray.h"
#include "max2times.h"
using namespace std;

TEST(testCase, test_pivotIndex_1)
{

    vector<int> nums{1, 2, 3};
    EXPECT_EQ(CentralIndexOfArray::Solution::pivotIndex(nums), -1);
}

TEST(testCase, test_pivotIndex_2)
{

    vector<int> nums{1, 7, 3, 6, 5, 6};
    EXPECT_EQ(CentralIndexOfArray::Solution::pivotIndex(nums), 3);
}

TEST(testCase, test_pivotIndex_3)
{

    vector<int> nums{-1, -1, -1, 0, 1, 1};
    EXPECT_EQ(CentralIndexOfArray::Solution::pivotIndex(nums), 0);
}

TEST(testCase, test_dominantIndex_1)
{
    vector<int> nums;
    EXPECT_EQ(Max2Times::Solution::dominantIndex(nums), -1);
}

TEST(testCase, test_dominantIndex_2)
{
    vector<int> nums{3, 6, 1, 0};
    EXPECT_EQ(Max2Times::Solution::dominantIndex(nums), 1);
}

TEST(testCase, test_dominantIndex_3)
{
    vector<int> nums{1, 2, 3, 4};
    EXPECT_EQ(Max2Times::Solution::dominantIndex(nums), -1);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
