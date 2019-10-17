#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  if(root == NULL){return NULL;}
  if(key < root->val_){ root->left_ = deleteNode(root->left_, key);}
  else if(key > root->val_){ root->right_ = deleteNode(root->right_, key);}
  else{
    //remove a node with 1 or no child
    if(root->left_==NULL){
      TreeNode * tmp = root->right_;
      delete root;
      root = NULL;
      return tmp;
    }
    if(root->right_ == NULL){
      TreeNode * tmp = root->left_;
      delete root;
      root = NULL;
      return tmp;
    }

    //remove a node with 2 children
    if(root->left_!=NULL && root->right_!=NULL){
      TreeNode * tmp1 = root;
      tmp1 = tmp1->right_;
      while(tmp1->left_!=NULL){
        tmp1 = tmp1->left_;
      }
      //pass value to root
      root->val_ = tmp1->val_;
      //delete right min node
      root->right_ = deleteNode(root->right_, tmp1->val_);
    }
  }

  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
