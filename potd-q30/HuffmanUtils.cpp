#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <map>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    HuffmanNode* root = huffmanTree;
    string s;
    int i = 0;

    while(i < (int)binaryString.length()){
    if(huffmanTree->left_ == NULL && huffmanTree->right_ == NULL){s += huffmanTree->char_; huffmanTree = root;}
    else{
      if(binaryString[i] == '0'){i++; if(huffmanTree->left_){huffmanTree = huffmanTree->left_;}}
      else if(binaryString[i] == '1'){i++; if(huffmanTree->right_){huffmanTree = huffmanTree->right_;}}
    }
    }
    s += huffmanTree->char_;
    return s;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */
map<char, string> ch;

void stringToBinaryhelper(string charString, HuffmanNode* huffmanTree) {
  if(huffmanTree == NULL){return;}
  if(huffmanTree->left_ == NULL && huffmanTree->right_ == NULL){ ch[huffmanTree->char_] = charString; }
  stringToBinaryhelper(charString + '0', huffmanTree->left_);
  stringToBinaryhelper(charString + '1', huffmanTree->right_);
}

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string result;
    stringToBinaryhelper("", huffmanTree);
    for(int i = 0; i < (int)charString.size(); i++){
      result += ch[charString[i]];
    }

    return result;
}
