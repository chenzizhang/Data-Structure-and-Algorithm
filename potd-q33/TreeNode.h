#pragma once

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode *parent_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      parent_ = NULL;
    }
};

void rightRotate(TreeNode* root);
void leftRotate(TreeNode* root);
void deleteTree(TreeNode* root);

//self-defined
int HeightCalculator(TreeNode* SubRoot);
bool isHeightBalanced(TreeNode* root);
// TreeNode* findLastUnbalanced(TreeNode* root);
