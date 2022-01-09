#include "Includes.h"

void printArray(int *array)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void emptyOccupied()
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        occupied[i] = 0;
    }
}

void printPopulation()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        printArray(population[i]);
    }
}

void shuffle(int *array)
{
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (NUM_NODES - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void copyArray(int *source, int *destination)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        destination[i] = source[i];
    }
}

void populate()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(seedPath);
        copyArray(seedPath, population[i]);
    }
}

void createRandomPath(int *path)
{
    int found;
    for (int i = 0; i < NUM_NODES; i++)
    {
        while (1)
        {
            int randomNode = rand() % NUM_NODES;
            found = 0;
            for (int j = 0; j <= i; j++)
            {
                if (path[j] == randomNode)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                path[i] = randomNode;
                break;
            }
        }
    }
}

void saveBestOfAll(int *newBestOfAll, int bestScore, int currentGeneration)
{
    copyArray(bestOfAll, bestOfAll);
    // SAVE TO FILE
}