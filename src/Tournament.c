#include "Includes.h"

int tournament()
{
    // printf("TOURNAMENT\n");

    int randomIndex1, randomIndex2;
    randomIndex1 = rand() % NUM_CHILDREN;
    randomIndex2 = rand() % NUM_CHILDREN;
    return scores[randomIndex1] < scores[randomIndex2] ? randomIndex1 : randomIndex2;
}