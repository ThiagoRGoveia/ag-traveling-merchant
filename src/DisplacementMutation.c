#include "Includes.h"

void displacementMutation(int *child, int subPathSize)
{
    int placeholder[subPathSize];
    int removalIndex = rand() % (NUM_NODES - subPathSize);
    int insertionIndex = rand() % (NUM_NODES - subPathSize);

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
}