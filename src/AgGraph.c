#include "Includes.h"

int child[NUM_NODES];
int population[NUM_CHILDREN][NUM_NODES];
int scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES];
int bestOfAllScore = INT_MAX;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int positionsArray[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int numberOfGenerations = 300;
int currentGeneration = 0;

void evolve(int *queenAg, int generationBestIndex)
{
    if (queenAg[GENOCIDE])
    {
        genocide();
        return;
    }
    int parentIndex = -1;
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i != parentIndex)
        {
            for (int j = 0; j < NUMBER_OF_QUEEN_AG_GENES_EXCLUDING_GENOCIDE; j++)
            {
                if (queenAg[j])
                {
                    switch (j)
                    {
                    case ELITISM:
                        parentIndex = generationBestIndex;
                        break;
                    case TOURNAMENT:
                        parentIndex = tournament();
                        break;
                    case ADAPTED_POSITION_BASED_CROSSOVER:
                        adaptedPositionBasedCrossover(population[parentIndex], population[i], child, adaptedPositionBasedCrossover_numberOfPositions);
                        break;
                    case ALTERNATING_POSITIONS_CROSSOVER:
                        alternatingPositionsCrossover(population[parentIndex], population[i], child);
                        break;
                    case MAXIMAL_PRESERVATIVE_CROSSOVER:
                        maximalPreservativeCrossover(population[parentIndex], population[i], child);
                        break;
                    case NO_CROSSOVER:
                        noCrossover(parentIndex);
                        break;
                    case DISPLACEMENT_MUTATION:
                        displacementMutation(child, displacementMutation_subPathSize);
                        break;
                    case EXCHANGE_MUTATION:
                        exchangeMutation(child, exchangeMutation_numberOfMutations);
                        break;
                    case INSERTION_MUTATION:
                        insertionMutation(child, insertionMutation_numberOfMutations);
                        break;
                    case PREDATION:
                        predation();
                        break;
                    }
                }
            }
        }
    }
}

int evolveGraphAg(int *queenAg)
{
    int generationBestIndex, generationBestScore;

    for (int i = 0; i < numberOfGenerations; i++)
    {
        currentGeneration++;
        generationBestIndex = evaluate();
        generationBestScore = scores[generationBestIndex];
        evolve(queenAg, generationBestIndex);
    }
    return generationBestScore;
}
