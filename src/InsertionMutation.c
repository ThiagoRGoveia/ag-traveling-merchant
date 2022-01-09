#include "Includes.h"

void insertionMutation(int *child, int numberOfMutations)
{
    int removalIndex, insertionIndex, temp;
    for (int i = 0; i < numberOfMutations; i++)
    {
        removalIndex = rand() % NUM_NODES;
        insertionIndex = rand() % NUM_NODES;
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
