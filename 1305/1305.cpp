#include <vector>
#include <iostream>
#include <gtest/gtest.h>

/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
*/


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode*left, TreeNode* right) : val(x), left(left), right(right){}
};

void DepthFirstTraversal(TreeNode* root, std::vector<int>& out){
    if (root == nullptr)
        return;

    DepthFirstTraversal(root->left, out);

    DepthFirstTraversal(root->right, out);

    out.push_back(root->val);
}

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
    std::vector<int> ret;

    DepthFirstTraversal(root1, ret);

    DepthFirstTraversal(root2, ret);

    std::sort(ret.begin(), ret.end());
    return ret;
}

void printModelAndResult(const std::vector<int>& model, const std::vector<int>& result){
    std::cout << "Model:  ";
    for (auto && i : model){
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Result: ";
    for (auto && i : result){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

TEST(Test, TestCase1){
    //arrange
    TreeNode root1{2, new TreeNode(1), new TreeNode(4)};
    TreeNode root2{1, new TreeNode(0), new TreeNode(3)};

    //act
    auto result = getAllElements(&root1, &root2);

    //assert
    std::vector<int> model{0,1,1,2,3,4};
    EXPECT_TRUE(result == model);

    printModelAndResult(model, result);
}

TEST(Test, TestCase2){
    //arrange
    TreeNode root1{1, nullptr, new TreeNode(8)};
    TreeNode root2{8, new TreeNode(1), nullptr};

    //act
    auto result = getAllElements(&root1, &root2);

    //assert
    std::vector<int> model{1,1,8,8};
    EXPECT_TRUE(result == model);
    printModelAndResult(model, result);
}


int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}