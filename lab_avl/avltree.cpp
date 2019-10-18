/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
using namespace std;

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
    t = u;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
    t = u;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    int balanceFactor = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
    //four conditions
    if(balanceFactor == -2){
      int balF = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
      if(balF == -1){
        rotateRight(subtree);
      }
      else{
        rotateLeftRight(subtree);
      }
    }

    if(balanceFactor == 2){
      int balF = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
      if(balF == 1){
        rotateLeft(subtree);
      }
      else{
        rotateRightLeft(subtree);
      }
    }

    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){subtree = new Node(key, value);}
    else if(key < subtree->key){
      insert(subtree->left, key, value);
    }
    else if(key > subtree->key){
      insert(subtree->right, key, value);
    }
    rebalance(subtree);

}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;

        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* iop = subtree->left;
            while(iop->right){
              iop = iop->right;
            }
            swap(subtree, iop);
            //we don't use subtree here because after swap, the iop value makes searching process goes to the right
            remove(subtree->left, key);

        } else {
            /* one-child remove */
            // your code here
            Node* Lchild = subtree->left;
            Node* Rchild = subtree->right;
            delete subtree;
            if(Lchild) {subtree = Lchild;}
            else{subtree = Rchild;}
        }
        // your code here
    }
    if(subtree) rebalance(subtree);
}
