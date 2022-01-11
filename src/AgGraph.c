#include "Includes.h"

int population[NUM_CHILDREN][NUM_NODES];
int scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES];
int bestOfAllScore = INT_MAX;
int seedPath[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int positionsArray[NUM_NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int numberOfGenerations = 300;
int currentGeneration = 0;

void evolve(Gene *queenAg, int generationBestIndex)
{

    if (queenAg[GENOCIDE].isActive)
    {
        genocide();
        return;
    }
    // printf("1.4.1\n");

    int parentIndex = generationBestIndex;
    // printf("1.4.2 -- %d -- ", parentIndex);
    // printArray(population[parentIndex]);

    if (queenAg[TOURNAMENT].isActive)
    {
        parentIndex = tournament();
    }
    // printf("1.4.3\n");
    // printf("START\n");
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i != parentIndex)
        {
            int child[NUM_NODES];
            for (int j = 2; j < NUMBER_OF_QUEEN_AG_GENES_EXCLUDING_GENOCIDE; j++)
            {
                if (queenAg[j].isActive)
                {
                    switch (j)
                    {
                    case ALTERNATING_POSITIONS_CROSSOVER:
                        // printf("i = %d\n", i);
                        // printf("parentIndex = %d\n", parentIndex);
                        // printArray(population[parentIndex]);
                        alternatingPositionsCrossover(population[parentIndex], population[i], child);
                        break;
                    case MAXIMAL_PRESERVATIVE_CROSSOVER:
                        maximalPreservativeCrossover(population[parentIndex], population[i], child);
                        break;
                    case NO_CROSSOVER:
                        copyArray(population[parentIndex], child);
                        break;
                    case DISPLACEMENT_MUTATION:
                        displacementMutation(child, queenAg[j].mutationPower);
                        break;
                    case EXCHANGE_MUTATION:
                        exchangeMutation(child, queenAg[j].mutationPower);
                        break;
                    case INSERTION_MUTATION:
                        insertionMutation(child, queenAg[j].mutationPower);
                        break;
                    case PREDATION:
                        predation();
                        break;
                    }
                }
            }
            copyArray(child, population[i]);
        }
    }

    // printf("END\n");
    // printf("1.4.4\n");
}

int evolveGraphAg(Gene *queenAg)
{
    int generationBestIndex, batchBest = INT_MAX;

    // printf("1\n");
    for (int i = 0; i < numberOfGenerations; i++)
    {
        // printf("1.1\n");

        currentGeneration++;
        generationBestIndex = evaluate();
        // printf("1.2 generationBestIndex = %d\n", generationBestIndex);

        if (scores[generationBestIndex] < batchBest)
        {
            batchBest = scores[generationBestIndex];
        }
        // printf("1.3\n");

        saveGenerationBestScore(currentGeneration, scores[generationBestIndex], population[generationBestIndex]);
        // printf("1.4\n");

        evolve(queenAg, generationBestIndex);
        // printf("1.5\n");
    }
    // printf("2\n");

    return batchBest;
}
