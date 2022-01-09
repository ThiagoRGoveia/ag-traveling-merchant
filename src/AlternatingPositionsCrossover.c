#include "Includes.h"

void alternatingPositionsCrossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    int counter = 0;
    for (int i = 0; i < NUM_NODES; i++)
    {
        if (counter < NUM_NODES && occupied[parentA[i]] == 0)
        {
            child[counter] = parentA[i];
            occupied[parentA[i]] = 1;
            counter++;
        }
        if (counter < NUM_NODES && occupied[parentB[i]] == 0)
        {
            child[counter] = parentB[i];
            occupied[parentB[i]] = 1;
            counter++;
        }
    }
}