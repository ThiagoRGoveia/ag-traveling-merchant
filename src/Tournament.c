#include "Includes.h"

int tournament()
{
    // printf("TOURNAMENT\n");

    int randomIndex1, randomIndex2;
    randomIndex1 = lrand48() % NUM_CHILDREN;
    randomIndex2 = lrand48() % NUM_CHILDREN;
    return scores[randomIndex1] < scores[randomIndex2] ? randomIndex1 : randomIndex2;
}