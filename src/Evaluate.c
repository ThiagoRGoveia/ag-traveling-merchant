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

int evaluate()
{
    int totalDistance, bestScore = INT_MAX, generationBest;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        totalDistance = calculateTotalDistance(population[i]);
        scores[i] = totalDistance;
        if (totalDistance < bestOfAllScore)
        {
            bestOfAllScore = totalDistance;
            bestScore = totalDistance;
            generationBest = i;
            saveBestOfAll(population[generationBest], bestOfAllScore, currentGeneration);
        }
        else if (totalDistance < bestScore)
        {
            bestScore = totalDistance;
            generationBest = i;
        }
    }
    // printArray(population[generationBest]);
    return generationBest;
}

int getDistance(int A, int B)
{
    return completeGraph[A][B];
}