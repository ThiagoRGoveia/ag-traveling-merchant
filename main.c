#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Node
{
    int distance;
    int *path;
} Node;
#define NUM_NODES 20
#define VECTOR_MAX_SIZE 25
#define NUM_CHILDREN 100
#define RANDOM_SEED 42

Node graph[VECTOR_MAX_SIZE * VECTOR_MAX_SIZE];
int parentA[VECTOR_MAX_SIZE];
int parentB[VECTOR_MAX_SIZE];
int population[NUM_CHILDREN][VECTOR_MAX_SIZE];
int occupied[VECTOR_MAX_SIZE];
int bestOfAll[VECTOR_MAX_SIZE]; //fodelona
int bestofAllIndex;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

void evaluate();
void emptyOccupied();
void crossover(int *parentA, int *parentB, int *child);
void mutation();
void createRandomPath(int *path);
void populate();
void shuffle(int *array);
void copyArray(int *source, int *destination);

int main()
{
    srand((unsigned)RANDOM_SEED);
    populate();
    // print populations
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        for (int j = 0; j < NUM_NODES; j++)
        {
            printf("%d ", population[i][j]);
        }
        printf("\n");
    }
    // shuffle(seedPath);
    // for (int i = 0; i < NUM_NODES; i++)
    // {
    //     printf("%d ", seedPath[i]);
    // }
    // printf("\n");
}

void evaluate()
{
}

void emptyOccupied()
{
    for (int i = 0; i < VECTOR_MAX_SIZE; i++)
    {
        occupied[i] = 0;
    }
}

void crossover(int *parentA, int *parentB, int *child)
{
    emptyOccupied();
    int counter = 0;
    for (int i = 0; i < VECTOR_MAX_SIZE; i++)
    {
        if (counter < VECTOR_MAX_SIZE && occupied[parentA[i]] == 0)
        {
            child[counter] = parentA[i];
            occupied[parentA[i]] = 1;
            counter++;
        }
        if (counter < VECTOR_MAX_SIZE && occupied[parentB[i]] == 0)
        {
            child[counter] = parentB[i];
            occupied[parentB[i]] = 1;
            counter++;
        }
    }
}

void mutation() {}

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