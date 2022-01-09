#include "graph.h"
#include "Includes.h"

int child[NUM_NODES];
int population[NUM_CHILDREN][NUM_NODES];
int scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES];
int bestScore = INT_MAX;
int bestOfAllIndex;
int worstOfAllIndex;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int positionsArray[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

int main()
{
    populate();
    while (1)
    {
        evaluate();
        elitism();
        printf("%d\n", bestScore);
    }
}
