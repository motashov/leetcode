#include <gtest/gtest.h>
#include <bits/stdc++.h>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ret;

    std::unordered_map<size_t, int> m;

    for (size_t i = 0; i<nums.size(); i++){
        auto found = m.find(target - nums[i]);
        if (found != m.end()){
            //pair found!!
            ret.push_back(found->second);
            ret.push_back(i);
        }else{
            //not found
            m.emplace(nums[i], i);
        }
    }


    return ret;
}

TEST(Test, TestCase1){
    //arrange
    std::vector<int> test{2,7,11,15};
    int target = 9;

    //act
    auto result = twoSum(test, target);

    //assert
    std::vector<int> model{0,1};
    EXPECT_TRUE(result == model);
}

TEST(Test, TestCase2){
    //arrange
    std::vector<int> test{3,2,4};
    int target = 6;

    //act
    auto result = twoSum(test, target);

    //assert
    std::vector<int> model{1,2};
    EXPECT_TRUE(result == model);
}

TEST(Test, TestCase3){
    //arrange
    std::vector<int> test{3,3};
    int target = 6;

    //act
    auto result = twoSum(test, target);

    //assert
    std::vector<int> model{0,1};
    EXPECT_TRUE(result == model);
}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
