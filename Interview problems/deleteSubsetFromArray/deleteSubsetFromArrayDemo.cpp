#include <iostream>
#include <vector>
#include <algorithm>

// We implement a function that removes a subset from an input array

void removeSubsetFromArray(int* inArray, int& size, const std::vector<int>& subset)
{
    if (size == 0) return;

    // for every i'th element of array, if the element a member of the subset, 
    // then the the element is "removed" from the array by shifting subsequent
    // elements of the array appropriately.
    
    unsigned shiftsToLeft = 0;
    for(int i = 0; i < size; i++)
    {
        if( std::find(subset.begin(), subset.end(), inArray[i]) != subset.end() )
        {
            ++shiftsToLeft;
            continue;
        }
        if (shiftsToLeft > 0)
        {
            inArray[i-shiftsToLeft] = inArray[i];
        }
    }
    size = size - shiftsToLeft;
}


int main(int argc, char const *argv[])
{
    int inArray[10] = {1,2,3,4};
    int arrSize = 4;
    std::vector<int> subset;
    subset.push_back(2);
    subset.push_back(4);

    removeSubsetFromArray(inArray, arrSize, subset);


    for (int i = 0; i < arrSize; ++i)
    {
        std::cout<<inArray[i]<<std::endl;
    }


    return 0;
}