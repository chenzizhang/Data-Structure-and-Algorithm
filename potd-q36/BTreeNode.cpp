#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    if(!root){return {};}
    if(root->is_leaf_){
      v.insert(v.end(),root->elements_.begin(), root->elements_.end());
      return v;
    }
    if(!root->is_leaf_){
      std::vector<int> u;
      for(unsigned i = 0; i < root->elements_.size(); i++){
        u = traverse(root->children_[i]);
        u.push_back(root->elements_[i]);
        v.insert(v.end(), u.begin(), u.end());
      }
      u = traverse(root->children_[root->elements_.size()]);
      v.insert(v.end(), u.begin(), u.end());
    }
    return v;
}
