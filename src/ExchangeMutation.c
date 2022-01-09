#include "Includes.h"

void exchangeMutation(int *child, int numberOfMutations)
{
    // printf("EXCHANGE MUTATION\n");

    for (int i = 0; i < numberOfMutations; i++)
    {
        int randomIndex1 = lrand48() % NUM_NODES;
        int randomIndex2 = lrand48() % NUM_NODES;
        int temp = child[randomIndex1];
        child[randomIndex1] = child[randomIndex2];
        child[randomIndex2] = temp;
    }
}