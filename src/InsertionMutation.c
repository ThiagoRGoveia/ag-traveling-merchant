#include "Includes.h"

void insertionMutation(int *child, int numberOfMutations)
{
    // printf("INSERTION MUTATION\n");

    int removalIndex, insertionIndex, temp;
    for (int i = 0; i < numberOfMutations; i++)
    {
        removalIndex = lrand48() % NUM_NODES;
        insertionIndex = lrand48() % NUM_NODES;
        temp = child[removalIndex];
        for (int i = removalIndex; i < NUM_NODES - 1; i++)
        {
            child[i] = child[i + 1];
        }
        for (int i = NUM_NODES - 1; i >= insertionIndex; i--)
        {
            child[i + 1] = child[i];
        }
        child[insertionIndex] = temp;
    }
}
