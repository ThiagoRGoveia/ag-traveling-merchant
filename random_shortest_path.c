#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

#define NUM_NODES 20
#define NUM_CHILDREN 100
#define RANDOM_SEED 42
#define MUTATION_RATE 2

int child[NUM_NODES];
int population[NUM_CHILDREN][NUM_NODES];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES]; //fodelona
int bestScore = INT_MAX;
int bestofAllIndex;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

void elitism();
void evaluate();
void emptyOccupied();
void crossover(int *parentA, int *parentB, int *child);
void mutation();
void createRandomPath(int *path);
void populate();
void shuffle(int *array);
void copyArray(int *source, int *destination);
void printArray(int *array);
int getDistance(int A, int B);
int calculateTotalDistance(int *array);
void printPopulation();

int main()
{
    populate();
    while (1) {
        evaluate();
        elitism();
        // printPopulation();
        printf("%d\n", bestScore);
    }
}

void printPopulation()
{
    for (int i = 0; i < NUM_CHILDREN; i++) {
        printArray(population[i]);
    }
}

void elitism()
{
    int bestScoreIndex = 0;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i != bestofAllIndex) {
            crossover(population[i], population[bestofAllIndex], child);
            mutation();
            copyArray(child, population[i]);
        }
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
        // printf("----%d\n", totalDistance);
        if (totalDistance < bestScore)
        {
            bestScore = totalDistance;
            copyArray(population[i], bestOfAll);
            bestofAllIndex = i;
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

void crossover(int *parentA, int *parentB, int *child)
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

void mutation() {
    for (int i = 0; i < MUTATION_RATE; i++) {
        int randomIndex1 = rand() % NUM_NODES;
        int randomIndex2 = rand() % NUM_NODES;
        int temp = child[randomIndex1];
        child[randomIndex1] = child[randomIndex2];
        child[randomIndex2] = temp;
    }
}

void genocide(int i) {
    shuffle(population[i]);
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