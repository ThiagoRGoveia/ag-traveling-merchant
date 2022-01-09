#include "Includes.h"

// int occupied[NUM_NODES] = {0};

// void printArray(int *array)
// {
//     for (int i = 0; i < NUM_NODES; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
// }

void maximalPreservativeCrossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    int counter = 0;
    for (int i = SUB_PATH_INITIAL_POSITION; i < SUB_PATH_INITIAL_POSITION + SUB_PATH_SIZE; i++)
    {
        occupied[parentA[i]] = 1;
        child[i - SUB_PATH_INITIAL_POSITION] = parentA[i];
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
//     maximalPreservativeCrossover(parentA, parentB, child);
//     printArray(child);
// }