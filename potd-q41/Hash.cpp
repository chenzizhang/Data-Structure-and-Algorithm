#include "Hash.h"
#include <string>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for(unsigned long i = 0; i < str.length(); i++){
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";
	//Your code here
	for(unsigned long i = 0; i < str.length(); i++){
		output.insert(output.begin(), str[i]);
	}
	return output;
}
