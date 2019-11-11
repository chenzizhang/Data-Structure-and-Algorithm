#include "Pattern.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

bool wordPattern(std::string pattern, std::string str) {

    //write your code here
    //1. save str (string set with space as split) into a vector
    std::vector<std::string> newstr;
    std::string word;

    for (char t : str) {
        if (t == ' ' && word.length() > 1) {
            newstr.push_back(word);
            word = "";
        } else if (t != ' ') {
            word += t;
        }
    }
    if (word != "") {
        newstr.push_back(word);
    }

    //2. Unique patterns as key, search for unmatch in str
    std::map<char, string> m;

    if(pattern.length() != newstr.size()) return false;

    for(unsigned i = 0; i < pattern.length(); i++){
      if(m.find(pattern[i]) == m.end()){
        m.insert(m.end(), std::pair<char, string>(pattern[i], newstr[i]));
      }
      else{
        if(m.at(pattern[i]) != newstr[i]){
          return false;
        }
      }
    }

    //3. Unique str as key, search for unmatch in pattern
    std::map<string, char> mm;
    for(unsigned i = 0; i < newstr.size(); i++){
      if(mm.find(newstr[i]) == mm.end()){
        mm.insert(mm.end(), std::pair<string, char>(newstr[i], pattern[i]));
      }
      else{
        if(mm.at(newstr[i]) != pattern[i]){
          return false;
        }
      }
    }
    
    return true;
}
