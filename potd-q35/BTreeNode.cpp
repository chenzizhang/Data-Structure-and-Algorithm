#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    unsigned i = 0;
    //go to the last ele which less or equal to key
    while(i < root->elements_.size() && root->elements_[i] < key){
      i ++;
    }

    //if equal to key, return
    if(root->elements_[i] == key){
      return root;
    }

    //if not equal and is leaf, stop
    if(root->is_leaf_){
      return NULL;
    }

    //if not equal, go next children and find
    return find(root->children_[i], key);

}
