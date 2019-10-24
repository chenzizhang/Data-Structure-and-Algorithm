#include <iostream>
#include <algorithm>
#include "tree.h"

template <class T>
void print(std::vector<T> v) {
	std::cout << "<";
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << (i != v.size()-1 ? ", " : "");
	}
	std::cout << ">" << std::endl;
}

int main() {
	Tree<int> t;

	// [case3]: empty Tree

	// t.setRoot(new Tree<int>::Node(1, NULL, NULL));
	t.setRoot(NULL);

	// [case2]: mixed tree with odd root

	// t.setRoot(
	// 	new Tree<int>::Node(1,
	// 		new Tree<int>::Node(4,
	// 			NULL,
	// 			new Tree<int>::Node(3)),
	// 		new Tree<int>::Node(6,
	// 			new Tree<int>::Node(8),
	// 			new Tree<int>::Node(31,
	// 				new Tree<int>::Node(10),
	// 				new Tree<int>::Node(12)))));

  // [case1]: mixed tree with even root

	// t.setRoot(
	// 	new Tree<int>::Node(2,
	// 		new Tree<int>::Node(4,
	// 			NULL,
	// 			new Tree<int>::Node(3)),
	// 		new Tree<int>::Node(6,
	// 			new Tree<int>::Node(8),
	// 			new Tree<int>::Node(31,
	// 				new Tree<int>::Node(10),
	// 				new Tree<int>::Node(12)))));


	std::vector<int> expected = { 2, 4, 6, 8, 10, 12};
	std::vector<int> actual;
	for ( int i : t ) actual.push_back(i);
	std::cout << "Expected: "; print(expected);
	std::cout << "Actual  : "; print(actual);
}
