#include "Includes.h"


int evolve(Gene *queenAg, int generationBestIndex)
{

    if (queenAg[GENOCIDE].isActive)
    {
        genocide();
        return 1;
    }

    int parentIndex = generationBestIndex;
    // printArray(population[parentIndex]);

    if (queenAg[TOURNAMENT].isActive)
    {
        parentIndex = tournament();
    }
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

    return 0;
}

int evolveGraphAg(Gene *queenAg)
{
    int generationBestIndex, batchBest = INT_MAX;

    int shouldBreak = 0;
    for (int i = 0; (i < numberOfGenerations && !shouldBreak); i++)
    {

        currentGeneration++;
        generationBestIndex = evaluate();

        if (scores[generationBestIndex] < batchBest)
        {
            batchBest = scores[generationBestIndex];
        }

        saveGenerationBestScore(currentGeneration, scores[generationBestIndex], population[generationBestIndex]);

        shouldBreak = evolve(queenAg, generationBestIndex);
    }

    return batchBest;
}
