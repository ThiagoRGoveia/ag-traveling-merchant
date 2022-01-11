#include "Includes.h"

void genocide()
{
    printf("GENOCIDE\n");

    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(population[i]);
    }
}