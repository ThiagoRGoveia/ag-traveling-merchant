
#include "Includes.h"

void adaptedPositionBasedCrossover(int *parentA, int *parentB, int *child, int numberOfPositions)
{
    emptyOccupied();
    shuffle(positionsArray);
    int positionsFilledInChild[NUM_NODES] = {0};
    int counter = 0;
    for (int i = 0; i < numberOfPositions; i++)
    {
        child[positionsArray[i]] = parentB[positionsArray[i]];
        occupied[parentB[positionsArray[i]]] = 1;
        positionsFilledInChild[positionsArray[i]] = 1;
    }
    for (int i = 0; i < NUM_NODES; i++)
    {
        if (positionsFilledInChild[i] == 0)
        {
            if (occupied[parentA[i]] == 0)
            {
                child[i] = parentA[i];
                occupied[parentA[i]] = 1;
            }
            else
            {
                child[i] = parentA[positionsArray[counter]];
                counter++;
            }
        }
    }
}
