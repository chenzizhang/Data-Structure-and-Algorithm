#include "TreeNode.h"
//Balancing an AVL Tree


TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  int l = -1;
  int r = -1;
  int child_l = -1;
  int child_r = -1;
  int fact = 0;
  int child_fact = 0;

  if(leftHeavy(subroot)){
    if(subroot->left_){
      l = getHeight(subroot->left_);
      if(subroot->left_->left_){
        child_l = getHeight(subroot->left_->left_);
      }
      if(subroot->left_->right_){
        child_r = getHeight(subroot->left_->right_);
      }
    }
    if(subroot->right_){
      r = getHeight(subroot->right_);
    }
  }
  else if(rightHeavy(subroot)){
    if(subroot->right_){
      r = getHeight(subroot->right_);
      if(subroot->right_->left_){
        child_l = getHeight(subroot->right_->left_);
      }
      if(subroot->right_->right_){
        child_r = getHeight(subroot->right_->right_);
      }
    }
    if(subroot->left_){
      l = getHeight(subroot->left_);
    }
  }
  fact = r - l;
  child_fact = child_r - child_l;

  if(fact == 2){
    if(child_fact == 1){
      return TreeNode::left;
    }
    else{
      return TreeNode::rightLeft;
    }
  }
  if(fact == -2){
    if(child_fact == -1){
      return TreeNode::right;
    }
    else{
      return TreeNode::leftRight;
    }
  }
  return TreeNode::right;
}
