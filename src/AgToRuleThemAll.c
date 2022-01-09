#include "Includes.h"

int kingAg[10] = {0, 1, 1, 0, 0, 1, 0, 0, 1, 0};

int adaptedPositionBasedCrossover_numberOfPositions = 1;
int displacementMutation_subPathSize = 1;
int exchangeMutation_numberOfMutations = 1;
int insertionMutation_numberOfMutations = 1;

void mutate(int *gene)
{
    *gene = rand() % MAX_MUTATION;
}

void checkPropertyMutation(int gene)
{
    switch (gene)
    {
    case ADAPTEDPOSITIONBASEDCROSSOVER:
        mutate(&adaptedPositionBasedCrossover_numberOfPositions);
        break;
    case DISPLACEMENTMUTATION:
        mutate(&displacementMutation_subPathSize);
        break;
    case EXCHANGEMUTATION:
        mutate(&exchangeMutation_numberOfMutations);
        break;
    case INSERTIONMUTATION:
        mutate(&insertionMutation_numberOfMutations);
        break;
    }
}

void mutate_kingAg()
{
    int gene;
    // mutate first phenotype
    gene = rand() % 2;
    kingAg[gene] = 1;
    kingAg[abs(gene - 1)] = 0;

    // mutate second phenotype
    gene = rand() % 4 + 2;
    if (gene = 5)
    {
        for (int i = 2; i < 4; i++)
            kingAg[i] = 0;
    }
    kingAg[gene] = 1;
    checkPropertyMutation(gene);
    for (int i = 2; i < 5; i++)
    {
        if (i != gene)
            kingAg[i] = 0;
    }

    // mutate third phenotype
    gene = rand() % 4 + 5;
    if (gene = 8)
    {
        for (int i = 4; i < 7; i++)
            kingAg[i] = 0;
    }
    kingAg[gene] = 1;
    checkPropertyMutation(gene);
    for (int i = 4; i < 7; i++)
    {
        if (i != gene)
            kingAg[i] = 0;
    }

    // mutate fourth phenotype
    gene = rand() % 2 + 8;
    kingAg[gene] = 1;
    kingAg[abs(gene - 9)] = 0;
}