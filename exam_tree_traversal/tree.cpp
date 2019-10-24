#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

/*******************
 ** verison2 **
 *******************/
 template <class T>
 Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
 	// TODO: your code here
	if(root!=NULL){
		if(root->data_ % 2 == 0){
			queue.push(root);
		}
		IteratorHelp(root);
		if(queue.empty()){
			curr_ = NULL;
		}
		else{curr_ = queue.front();} //in case of root is odd
	}

 }

 template <class T> //queue: same order with preorder(root, left, right)
 void Tree<T>::Iterator::IteratorHelp(Tree::Node *root){
 	if(!root){return;}
 	if(root->left_ == NULL && root->right_ == NULL){
 		return;
 	}
	if(root->left_){
		if(root->left_->data_ % 2 == 0){
			queue.push(root->left_);
		}
		IteratorHelp(root->left_);
	}
	if(root->right_){
		if(root->right_->data_ % 2 == 0){
			queue.push(root->right_);
		}
		IteratorHelp(root->right_);
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
 	return T(); //(note: calling operator* on an end iterator should return a default value of type T)

 }




/*******************
 ** verison1 **
 *******************/


// template <class T>
// Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
// 	// TODO: your code here
// 	if(root!=NULL){
// 		IteratorHelp(root);
// 		if(root->data_ %2 == 0){
// 			stack.push(root);
// 		}
// 	}
//
// }
//
// template <class T>
// void Tree<T>::Iterator::IteratorHelp(Tree::Node *root){
// 	if(!root){return;}
// 	if(root->left_ == NULL && root->right_ == NULL){
// 		return;
// 	}
// 	if(root->right_){
// 		IteratorHelp(root->right_);
// 		stack.push(root->right_);
// 	}
// 	if(root->left_){
// 		IteratorHelp(root->left_);
// 		stack.push(root->left_);
// 	}
// }
//
//
// template <class T>
// typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
// 	// TODO: your code here
// 	// if(!stack.empty()){
// 	// 	curr_ = stack.top();
// 	// 	stack.pop();
// 	//
// 	// 	if(curr_->right_){
// 	// 		stack.push(curr_->right_);
// 	// 	}
// 	// 	if(curr_->left_){
// 	// 		stack.push(curr_->left_);
// 	// 	}
// 	//
// 	// 	if(stack.empty()){
// 	// 		curr_ = NULL;
// 	// 	}
// 	// 	else if(stack.top()->data_ % 2 == 0){
// 	// 		curr_ = stack.top();
// 	// 	}
// 	// 	else if(stack.top()->data_ % 2 == 1){
// 	// 		if(stack.size() == 1){
// 	// 			curr_ = stack.top();
// 	// 		}
// 	// 		else{
// 	// 			stack.pop();
// 	// 			curr_ = stack.top();
// 	// 		}
// 	// 	}
// 	// }
// 	//*********************
// 	// if(!queue.empty()){
// 	// 	queue.pop();
// 	// 	if(queue.empty()){
// 	// 		curr_ = NULL;
// 	// 	}
// 	// 	else{
// 	// 		curr_ = queue.front();
// 	// 		while(curr_->data_ % 2 == 1){
// 	// 			queue.pop();
// 	// 			curr_ = queue.front();
// 	// 		}
// 	// 	}
// 	//
// 	// }
// 	if(!stack.empty()){
// 		stack.pop();
// 		if(stack.empty()){
// 			curr_ = NULL;
// 		}
// 		else{
// 			curr_ = stack.top();
// 			while(curr_->data_ % 2 == 1){
// 				stack.pop();
// 				curr_ = stack.top();
// 			}
// 		}
// 	}
// 	else{
// 		curr_ = NULL;
// 	}
// 	return *this;
// }
//
// template <class T>
// T Tree<T>::Iterator::operator*() const {
// 	// TODO: your code here
// 	return curr_->data_;
// }
//


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
