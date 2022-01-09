#include "Includes.h"

void displacementMutation(int *child, int subPathSize)
{
    // printf("DISPLACEMENT MUTATION\n");

    int placeholder[subPathSize];
    int removalIndex = lrand48() % (NUM_NODES - subPathSize);
    int insertionIndex = lrand48() % (NUM_NODES - subPathSize);
    for (int i = 0; i < subPathSize; i++)
    {
        placeholder[i] = child[removalIndex + i];
    }

    for (int i = removalIndex; i < (NUM_NODES - subPathSize); i++)
    {
        child[i] = child[i + subPathSize];
    }

    for (int i = NUM_NODES - subPathSize; i >= insertionIndex; i--)
    {
        child[i + subPathSize] = child[i];
    }
    for (int i = 0; i < subPathSize; i++)
    {
        child[insertionIndex + i] = placeholder[i];
    }
    // printArray(child);
}
