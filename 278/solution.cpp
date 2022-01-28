#include <vector>
#include <iostream>
#include <gtest/gtest.h>


/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check.
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

namespace{
    int bad;
}

// The API isBadVersion is defined for you.
bool isBadVersion(int version){
    if (version >= ::bad){
        return true;
    }
    return false;
}


int firstBadVersion(int n) {
    size_t low = 1;
    size_t high = n;
    size_t half = (low+high)/2;
    while(low < high){

        if (isBadVersion(half)){
            high = half;
        }
        else {
            low = half+1;

        }
        half = (low + high) / 2;
    }
    return half;
}

TEST(Test1, TestCase1){
    //arrange
    int test = 5;
    ::bad = 4;

    //act
    auto result = firstBadVersion(test);

    //assert
    EXPECT_EQ(result, ::bad);
}

TEST(Test2, TestCase2){
    //arrange
    int test = 1;
    ::bad = 1;

    //act
    auto result = firstBadVersion(test);

    //assert
    EXPECT_EQ(result, ::bad);
}

TEST(Test3, TestCase2){
    //arrange
    int test = 2;
    ::bad = 2;

    //act
    auto result = firstBadVersion(test);

    //assert
    EXPECT_EQ(result, ::bad);
}



TEST(Test4, TestCase2){
    //arrange
    int test = INT32_MAX;
    ::bad = INT32_MAX;

    //act
    auto result = firstBadVersion(test);

    //assert
    EXPECT_EQ(result, ::bad);
}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}