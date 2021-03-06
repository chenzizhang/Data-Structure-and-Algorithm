#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {

    // Your code here
    TreeNode* parent = root->parent_;
    TreeNode* u = root->left_;
    root->left_ = u->right_;
    u->right_ ->parent_ = root;

    u->right_ = root;
    root->parent_ = u;
    u->parent_ = parent;

}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode* parent = root->parent_;
    TreeNode* u = root->right_;
    root->right_ = u->left_;
    u->left_ ->parent_ = root;

    u->left_ = root;
    root->parent_ = u;
    u->parent_ = parent;

}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

int HeightCalculator(TreeNode* SubRoot){
  int leftHeight = -1;
  int rightHeight = -1;
  if(SubRoot ==  NULL){return -1;}
  else{
    if(SubRoot->left_){
      leftHeight = HeightCalculator(SubRoot->left_);
    }
    if(SubRoot->right_){
      rightHeight = HeightCalculator(SubRoot->right_);
    }
  }
  return fmax(leftHeight, rightHeight) + 1;
}

bool isHeightBalanced(TreeNode* root) {
  int leftHeight = -1;
  int rightHeight = -1;
  if(root == NULL){return true;}
  else{
    leftHeight = HeightCalculator(root->left_);
    rightHeight = HeightCalculator(root->right_);
    int balance = leftHeight - rightHeight;
    if(balance >= -1 && balance <= 1){
    return true;
    }
    return false;
  }

}



TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  TreeNode* left = NULL;
  TreeNode* right = NULL;
  TreeNode* start = root;

  if(root == NULL ){return NULL;}
  if(root->left_ != NULL){
    left = findLastUnbalanced(root->left_);
  }
  if(root->right_ != NULL){
    right = findLastUnbalanced(root->right_);
  }

  //if two side Balanced
  if(left == NULL && right == NULL){
    if(isHeightBalanced(root)){
      return NULL;
    }
    return root;
  }
  //if one side unblanced
  else if(left != NULL && right != NULL){
    if(HeightCalculator(start) - HeightCalculator(left) >= HeightCalculator(start) - HeightCalculator(right)){
      return findLastUnbalanced(left);
    }
    else{
      return findLastUnbalanced(right);
    }
  }
  else{
    if(left){return left;}
    return right;
  }

}
