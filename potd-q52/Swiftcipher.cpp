#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
		ifstream infile (filename);
		string line;
		vector<int> content;
		map<string, int> dic;


		string word;
		if (infile.is_open()) {
				while (getline(infile, line)) {
						map<string, int>::iterator it = dic.find(line);
						if (it == dic.end()) {
								dic[line] = 1;
						} else {
								it->second += 1;
						}
				}
		}
		infile.close();

		for (auto iterator: dic) {
				content.push_back(iterator.second);
		}
		sort(content.begin(), content.end());

		string message;
		for (unsigned i = 0; i < content.size(); i++) {
			for (auto it: dic) {
					if (it.second == content[i]) {
						message += it.first;
						if (i != content.size() - 1) {
							message += " ";
						}
						break;
					}
	    }
    }

		return message;

}
