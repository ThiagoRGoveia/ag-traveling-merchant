#include "Includes.h"

void predation()
{
    // printf("PREDATION\n");

    int worstOfAllIndex = 0;
    int worstScore = INT_MIN;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (scores[i] > worstScore)
        {
            worstScore = scores[i];
            worstOfAllIndex = i;
        }
    }
    shuffle(population[worstOfAllIndex]);
}