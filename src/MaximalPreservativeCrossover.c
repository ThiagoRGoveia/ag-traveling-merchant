#include "Includes.h"

void maximalPreservativeCrossover(int *parentA, int *parentB, int *child)
{
    // printf("MAXIMAL PRESERVATIVE CROSSOVER\n");

    emptyOccupied();
    int randomStartIndex = lrand48() % NUM_NODES / 4;
    int subPathSize = (NUM_NODES / 4);
    int counter = 0;
    for (int i = randomStartIndex; i < randomStartIndex + subPathSize; i++)
    {
        occupied[parentA[i]] = 1;
        child[i - randomStartIndex] = parentA[i];
        counter++;
    }
    for (int i = 0; i < NUM_NODES; i++)
    {
        if (occupied[parentB[i]] == 0)
        {
            child[counter] = parentB[i];
            occupied[parentB[i]] = 1;
            counter++;
        }
    }
}

// int main()
// {
//     int child[NUM_NODES] = {0};
//     int parentA[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//     int parentB[NUM_NODES] = {1, 2, 4, 6, 8, 7, 5, 0, 3};

//     // printArray(child);
//     maximalPreservativeCrossover(parentA, parentB, child, 3);
//     printArray(child);
// }