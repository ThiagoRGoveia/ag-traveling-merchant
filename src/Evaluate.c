#include "Includes.h"

int calculateTotalDistance(int *array)
{
    int totalDistance = 0;
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        totalDistance += getDistance(array[i], array[i + 1]);
    }
    return totalDistance;
}

void evaluate()
{
    int totalDistance;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        totalDistance = calculateTotalDistance(population[i]);
        scores[i] = totalDistance;
        if (totalDistance < bestScore)
        {
            bestScore = totalDistance;
            copyArray(population[i], bestOfAll);
            bestOfAllIndex = i;
        }
    }
}

int getDistance(int A, int B)
{
    return completeGraph[A][B];
}