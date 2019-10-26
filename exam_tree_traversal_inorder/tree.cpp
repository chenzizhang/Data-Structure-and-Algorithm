#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here
	if(root!=NULL){
		IteratorHelper(root);
		if(!queue.empty()){
			curr_ = queue.front();
		}
		else{
			curr_ = NULL;
		}
	}
}

template <class T>
void Tree<T>::Iterator::IteratorHelper(Tree::Node *root){
	if(root==NULL){return;}
	if(root->right_==NULL && root->left_==NULL){if(root->data_!=NULL){queue.push(root);}return;}
	if(root->right_){
		IteratorHelper(root->right_);
	}
	if(root->data_!=NULL){queue.push(root);}
	if(root->left_){
		IteratorHelper(root->left_);
	}


}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here
	curr_ = NULL;
  if(!queue.empty()){
		queue.pop();
		if(!queue.empty()){
			curr_ = queue.front();
		}
	}
	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	if(curr_ != NULL){return curr_->data_;}
	return T(); // remove this line
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif
