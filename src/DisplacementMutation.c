#include "Includes.h"

void displacementMutation(int *child, int subPathSize)
{
    // printf("DISPLACEMENT MUTATION\n");
    // printf("1\n");
    int placeholder[subPathSize];
    int removalIndex = lrand48() % (NUM_NODES - subPathSize);
    int insertionIndex = lrand48() % (NUM_NODES - subPathSize);
    // printf("2\n");
    for (int i = 0; i < subPathSize; i++)
    {
        placeholder[i] = child[removalIndex + i];
    }
    // printf("3\n");

    for (int i = removalIndex; i < (NUM_NODES - subPathSize); i++)
    {
        child[i] = child[i + subPathSize];
    }
    // printf("4\n");

    for (int i = NUM_NODES - subPathSize; i >= insertionIndex; i--)
    {
        child[i + subPathSize] = child[i];
    }
    // printf("5\n");

    for (int i = 0; i < subPathSize; i++)
    {
        child[insertionIndex + i] = placeholder[i];
    }
    // printf("6\n");

    // printArray(child);
}
