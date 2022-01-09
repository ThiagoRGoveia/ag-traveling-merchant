#include "Includes.h"

void tournament()
{
    int randomIndex1, randomIndex2;
    randomIndex1 = rand() % NUM_CHILDREN;
    randomIndex2 = rand() % NUM_CHILDREN;
    parentIndex = scores[randomIndex1] < scores[randomIndex2] ? randomIndex1 : randomIndex2;
}