#include <cstdio>
#include <cstdlib>
#include "DiscreteDataNoiseFilter.hpp"

int main(int argc, char const *argv[])
{
    DiscreteDataNoiseFilter myFilter;
    myFilter.setEstimatedNoise(2);

    int arrSamples[]        = {1, 1, 1, 2, 3, 2, 2, 3, 3, 3, 3, 3, 2, 2, 3, 2, 2, 2 };
    int expectedOutput[]    = {1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2 }; 
    int numElements = sizeof(arrSamples)/sizeof(int);
    printf("numElements = %d\n", numElements );

    for (int i = 0; i < numElements; ++i)
    {
        int out = myFilter.filter(arrSamples[i]);
        printf("out = %d\n", out );

        // validation 
        if (out != expectedOutput[i])
        {
            printf("Validation: Incorrect output[%d]: %d. Should have been %d.  \n", i , out, expectedOutput[i]);
            return -1;
        }
    }

    return 0;
}