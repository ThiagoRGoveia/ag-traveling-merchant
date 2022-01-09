#include "Includes.h"

void genocide()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(population[i]);
    }
}