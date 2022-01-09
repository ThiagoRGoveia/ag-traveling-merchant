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
    int totalDistance, bestScore, bestScoreIndex;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        totalDistance = calculateTotalDistance(population[i]);
        scores[i] = totalDistance;
        if (totalDistance < bestOfAllScore)
        {
            bestOfAllScore = totalDistance;
            bestScore = totalDistance;
            bestScoreIndex = i;
            saveBestOfAll(population[bestScoreIndex], bestOfAllScore, currentGeneration);
        }
        else if (totalDistance < bestScore)
        {
            bestScore = totalDistance;
            bestScoreIndex = i;
        }
    }
    // printArray(population[bestScoreIndex]);
    return bestScoreIndex;
}

int getDistance(int A, int B)
{
    return completeGraph[A][B];
}