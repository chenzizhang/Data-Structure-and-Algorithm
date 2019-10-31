#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    std::vector<int>* array = new std::vector<int>(M);	// Hint: This comes in handy
	int permutation_count = 0;
	float goodness = 0;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		permutation_count ++;
		(*array)[bernstein(str, M)] ++;

	} while(std::next_permutation(str.begin(), str.end()));

	//Code for determining goodness
	for(unsigned i = 0; i < array->size(); i++){
		if((*array)[i] >1) goodness += (*array)[i]-1;
	}

	return goodness/float(M);
}
