#include "Includes.h"

void noCrossover()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i == parentIndex)
            continue;
        copyArray(population[parentIndex], population[i]);
    }
}