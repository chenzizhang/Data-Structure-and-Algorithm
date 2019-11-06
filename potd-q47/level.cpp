#include "MinHeap.h"
#include <cmath>

vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        int size = heap.elements.size()-1; //NOTE: Our implementation of heaps is 1-based indexing.
        //Think about what the actual size of the heap is based on the size of the array.
        int height = std::log2(size);

        vector<int> lastLevels;

        for(int i = pow(2, height); i <= size; i++){
          lastLevels.push_back(heap.elements[i]);
        }
        return lastLevels;
}
