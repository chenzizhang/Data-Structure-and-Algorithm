#include <iostream>
#include "TreeNode.h"

using namespace std;

const string RED_TEXT = "\033[1;31m";
const string GREEN_TEXT = "\033[1;32m";
const string RESET_TEXT = "\033[0m";

void print_pass(string message) {
  cout<<GREEN_TEXT<<"TEST PASSED"<<RESET_TEXT<<": "<<message<<endl;
}

void print_fail(string message) {
  cout<<RED_TEXT<<"TEST FAILED"<<RESET_TEXT<<": "<<message<<endl;
  exit(1);
}

int main() {

    TreeNode *example =
        new TreeNode(1,
                new TreeNode(2),
                new TreeNode(3,
                    new TreeNode(4),
                    new TreeNode(5,
                        new TreeNode(6),
                        new TreeNode(7))));


    // Try complete

    TreeNode *x = makeFullRight(7);

    cout << "Result of makeFullRight: " << endl;
    
    if (equal(x,example))
        print_pass("");
    else
        print_fail("");

    // Clean up

    delete x;
    delete example;
}
