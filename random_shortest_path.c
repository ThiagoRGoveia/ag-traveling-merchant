#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#define NUM_NODES 20
#define NUM_CHILDREN 100
#define RANDOM_SEED 42
#define INITIAL_MUTATION_RATE 1
#define SUB_PATH_SIZE 5             // vale no maximo NUM_NODES/2
#define SUB_PATH_INITIAL_POSITION 2 // vale de 0 a NUM_NODES/2

typedef struct
{
    int index;
    int score;
    int accumulatedScore;
} Score;

int child[NUM_NODES];
int population[NUM_CHILDREN][NUM_NODES];
Score scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int seletedParent[NUM_NODES]; // fodelona
int bestOfAll[NUM_NODES];     // fodelona
int worstOfAll[NUM_NODES];    // genocidio
int bestScore = INT_MAX;
int bestOfAllIndex;
int worstOfAllIndex;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int mutationRate = INITIAL_MUTATION_RATE;

void elitism();
void tournament();
// void roulette();
void predation();
void genocide();
void evaluate();
void emptyOccupied();
void alternatingPositionsCrossover(int *parentA, int *parentB, int *child);
void maximalPreservativeCrossover(int *parentA, int *parentB, int *child);
void adaptedPositionBasedCrossover(int *parentA, int *parentB, int *child);
void crossover4(int *parentA, int *parentB, int *child);
void mutation1(int *child);
void createRandomPath(int *path);
void populate();
void shuffle(int *array);
void copyArray(int *source, int *destination);
void printArray(int *array);
int getDistance(int A, int B);
int calculateTotalDistance(int *array);
void printPopulation();
// void mergeSortScores();
// int calculateAccumulatedScores();

int main()
{
    populate();
    while (1)
    {
        evaluate();
        elitism();
        // printPopulation();
        printf("%d\n", bestScore);
    }
}

void printPopulation()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        printArray(population[i]);
    }
}

void elitism()
{
    int bestScoreIndex = 0;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i != bestOfAllIndex)
        {
            crossover(population[i], population[bestOfAllIndex], child);
            mutation(child);
            copyArray(child, population[i]);
        }
    }
}

void tournament()
{
    int randomIndex1, randomIndex2, parentIndex;
    randomIndex1 = rand() % NUM_CHILDREN;
    randomIndex2 = rand() % NUM_CHILDREN;
    parentIndex = scores[randomIndex1].score < scores[randomIndex2].score ? randomIndex1 : randomIndex2;
    copyArray(population[parentIndex], seletedParent);
}

// void roulette()
// {
//     mergeSortScores();
//     int biggestAccumulatedScore = calculateAccumulatedScores();
//     int targetScore = rand() % biggestAccumulatedScore;
//     for (int i = 0; i < NUM_CHILDREN; i++)
//     {
//         if (targetScore < scores[i].accumulatedScore)
//         {
//             crossover(population[i], population[scores[i].index], child);
//             mutation(child);
//             copyArray(child, population[i]);
//             break;
//         }
//     }
// }

void predation()
{
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

void genocide()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(population[i]);
    }
}

int calculateTotalDistance(int *array)
{
    int totalDistance = 0;
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        totalDistance += getDistance(array[i], array[i + 1]);
    }
    return totalDistance;
}

int getDistance(int A, int B)
{
    return completeGraph[A][B];
}

void printArray(int *array)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void evaluate()
{
    int totalDistance;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        totalDistance = calculateTotalDistance(population[i]);
        scores[i].index = i;
        scores[i].score = totalDistance;
        if (totalDistance < bestScore)
        {
            bestScore = totalDistance;
            copyArray(population[i], bestOfAll);
            bestOfAllIndex = i;
        }
    }
}

void emptyOccupied()
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        occupied[i] = 0;
    }
}

void alternatingPositionsCrossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    int counter = 0;
    for (int i = 0; i < NUM_NODES; i++)
    {
        if (counter < NUM_NODES && occupied[parentA[i]] == 0)
        {
            child[counter] = parentA[i];
            occupied[parentA[i]] = 1;
            counter++;
        }
        if (counter < NUM_NODES && occupied[parentB[i]] == 0)
        {
            child[counter] = parentB[i];
            occupied[parentB[i]] = 1;
            counter++;
        }
    }
}

void maximalPreservativeCrossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    for (int i = SUB_PATH_INITIAL_POSITION; i < SUB_PATH_SIZE; i++)
    {
        occupied[parentA[i]] = 1;
        child[i - SUB_PATH_INITIAL_POSITION] = parentA[i];
    }
    for (int i = SUB_PATH_SIZE; i < NUM_NODES; i++)
    {
        if (occupied[parentB[i]] == 0)
        {
            child[i] = parentB[i];
            occupied[parentB[i]] = 1;
        }
    }
}

void adaptedPositionBasedCrossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    int counter = 0;
    for (int i = 0; i < NUM_NODES; i++)
    {
        // PAREI AQUI
    }
}

void mutation1(int *child)
{
    for (int i = 0; i < mutationRate; i++)
    {
        int randomIndex1 = rand() % NUM_NODES;
        int randomIndex2 = rand() % NUM_NODES;
        int temp = child[randomIndex1];
        child[randomIndex1] = child[randomIndex2];
        child[randomIndex2] = temp;
    }
}

void createRandomPath(int *path)
{
    int found;
    for (int i = 0; i < NUM_NODES; i++)
    {
        while (1)
        {
            int randomNode = rand() % NUM_NODES;
            found = 0;
            for (int j = 0; j <= i; j++)
            {
                if (path[j] == randomNode)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                path[i] = randomNode;
                break;
            }
        }
    }
}

void populate()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(seedPath);
        copyArray(seedPath, population[i]);
    }
}

void shuffle(int *array)
{
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (NUM_NODES - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void copyArray(int *source, int *destination)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        destination[i] = source[i];
    }
}

// void mergeSortScores()
// {
//     int i, j, k;
//     Score temp;
//     for (i = 1; i < NUM_CHILDREN; i++)
//     {
//         temp = scores[i];
//         j = i - 1;
//         while (j >= 0 && scores[j].score < temp.score)
//         {
//             scores[j + 1] = scores[j];
//             j = j - 1;
//         }
//         scores[j + 1] = temp;
//     }
// }

// int calculateAccumulatedScores()
// {
//     int total = 0;
//     for (int i = 0; i < NUM_CHILDREN; i++)
//     {
//         total += scores[i].score;
//         scores[i].accumulatedScore = total;
//     }
//     return total;
// }