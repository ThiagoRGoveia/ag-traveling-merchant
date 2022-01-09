#include "Includes.h"

void evolve(int parentIndex)
{
    if (kingAg[GENOCIDE])
    {
        genocide();
        return;
    }
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        if (i != parentIndex)
        {
            for (int j = 0; j < NUMBER_OF_KING_AG_GENES_EXCLUDING_GENOCIDE; j++)
            {
                if (kingAg[j])
                {
                    switch (j)
                    {
                    case ELITISM:
                        elitism();
                        break;
                    case TOURNAMENT:
                        tournament();
                        break;
                    case ADAPTEDPOSITIONBASEDCROSSOVER:
                        adaptedPositionBasedCrossover(population[parentIndex], population[i], child, adaptedPositionBasedCrossover_numberOfPositions);
                        break;
                    case ALTERNATINGPOSITIONSCROSSOVER:
                        alternatingPositionsCrossover(population[parentIndex], population[i], child);
                        break;
                    case MAXIMALPRESERVATIVECROSSOVER:
                        maximalPreservativeCrossover(population[parentIndex], population[i], child);
                        break;
                    case DISPLACEMENTMUTATION:
                        displacementMutation(child, displacementMutation_subPathSize);
                        break;
                    case EXCHANGEMUTATION:
                        exchangeMutation(child, exchangeMutation_numberOfMutations);
                        break;
                    case INSERTIONMUTATION:
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