#include "graph.h"
#include "Includes.h"

int child[NUM_NODES];
int population[NUM_CHILDREN][NUM_NODES];
int scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES];
int worstOfAll[NUM_NODES];
int bestScore = INT_MAX;
int bestOfAllIndex;
int worstOfAllIndex;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int mutationRate = INITIAL_MUTATION_RATE;

void crossover4(int *parentA, int *parentB, int *child);
void mutation1(int *child);

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
