#include <vector>
#include <gtest/gtest.h>

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

int search(std::vector<int>& nums, int target) {
    int max = nums.size() - 1;
    int min = 0;

    int half = (min + max) / 2;

    while (min <= max){
        if (nums[half] == target){
            return half;
        }

        if (nums[half] > target){
            max = half - 1;
        }

        if (nums[half] < target){
            min = half + 1;
        }

        half = (min + max) / 2;
    }

    return -1;
}



TEST(Test, TestCase1){
    //arrange
    std::vector<int> nums{-1,0,3,5,9,12};

    //act
    auto result = search(nums, 9);

    //assert
    EXPECT_TRUE(result == 4);
}

TEST(Test, TestCase2){
    //arrange
    std::vector<int> nums{-1,0,3,5,9,12};

    //act
    auto result = search(nums, 2);

    //assert
    EXPECT_TRUE(result == -1);
}

TEST(Test, TestCase3){
    //arrange
    std::vector<int> nums{12};

    //act
    auto result = search(nums, 2);

    //assert
    EXPECT_TRUE(result == -1);
}

TEST(Test, TestCase4){
    //arrange
    std::vector<int> nums{-1};

    //act
    auto result = search(nums, -1);

    //assert
    EXPECT_TRUE(result == 0);
}

TEST(Test, TestCase5){
    //arrange
    std::vector<int> nums{12};

    //act
    auto result = search(nums, 22);

    //assert
    EXPECT_TRUE(result == -1);
}


TEST(Test, TestCase6){
    //arrange
    std::vector<int> nums;

    //act
    auto result = search(nums, 22);

    //assert
    EXPECT_TRUE(result == -1);
}



int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}