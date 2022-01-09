#include "Includes.h"

void exchangeMutation(int *child, int numberOfMutations)
{
    for (int i = 0; i < numberOfMutations; i++)
    {
        int randomIndex1 = rand() % NUM_NODES;
        int randomIndex2 = rand() % NUM_NODES;
        int temp = child[randomIndex1];
        child[randomIndex1] = child[randomIndex2];
        child[randomIndex2] = temp;
    }
}