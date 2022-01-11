#include "Includes.h"

void alternatingPositionsCrossover(int *parentA, int *parentB, int *child)
{
    // printf("ALTERNATING POSITION BASED CROSSOVER\n");
    // printf("1\n");

    emptyOccupied();
    // printf("1.2\n");
    int counter = 0;
    for (int i = 0; i < NUM_NODES; i++)
    {
        // printf("1.2.1\n");
        // printf("%d\n", counter);
        // printArray(parentA);
        // printArray(occupied);
        // printf("%d, %d\n", i, parentA[i]);
        if (counter < NUM_NODES && occupied[parentA[i]] == 0)
        {
            // printf("1.2.1.1\n");
            child[counter] = parentA[i];
            // printf("1.2.1.2\n");
            occupied[parentA[i]] = 1;
            // printf("1.2.1.3\n");
            counter++;
            // printf("1.2.1.4\n");
        }
        // printf("1.2.2\n");

        if (counter < NUM_NODES && occupied[parentB[i]] == 0)
        {
            child[counter] = parentB[i];
            occupied[parentB[i]] = 1;
            counter++;
        }
        // printf("1.2.3\n");
    }
    // printf("1.3\n");
}