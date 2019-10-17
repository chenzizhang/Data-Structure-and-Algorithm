#include "TreeNode.h"
#include <cmath>

bool isHeightBalanced(TreeNode* root) {
  // your code here
  int balance = BalancedHelper(root->left_) - BalancedHelper(root->right_);
  if(balance > -1 && balance < 1){
    return true;
  }

  return false;
}

int BalancedHelper(TreeNode* SubRoot){
  int heightleft = -1;
  int heightright = -1;

  if(SubRoot == NULL){return -1;}
  else{
    if(SubRoot->left_ != NULL){
      heightleft = BalancedHelper(SubRoot->left_);
    }
    if(SubRoot->right_ != NULL){
      heightright = BalancedHelper(SubRoot->right_);
    }
  }
  return fmax(heightleft,heightright) + 1;
}


void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
