#include "Includes.h"

long int getDistance(int A, int B)
{
    return completeGraph[A][B];
}

long long int calculateTotalDistance(int *array)
{
    long int totalDistance = 0;
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        totalDistance += getDistance(array[i], array[i + 1]);
    }
    return totalDistance;
}

int evaluate()
{
    long long int totalDistance;
    int bestScore = INT_MAX, generationBest;
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

