#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int>& mapA,
                                        unordered_map<string, int>& mapB) {

    // your code here

    //init a blank result map
    unordered_map<string, int> result({});

    //if both are not empty
    if(!mapA.empty() && !mapB.empty()){

      //iterate from mapA.begin
      unordered_map<string, int>::iterator it = mapA.begin();
      //when iterator doesn't reach mapA.end
      while(it != mapA.end()){
        //find the common key in mapA and mapB at this iterator
        unordered_map<string, int>::iterator got = mapB.find(it->first);
        //if not found, go to next point
        if(got == mapA.end()){it++;}
        else{
          //if found, insert the added up value to result; erase it from mapA and mapB; reset it to mapA.begin
          result.insert({got->first, mapA.at(got->first) + mapB.at(got->first)});
          mapA.erase(it);
          mapB.erase(got);
          it = mapA.begin();
        }
      }
    }


    return result;
}
