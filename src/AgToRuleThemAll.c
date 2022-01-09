#include "Includes.h"

int kingAg[11] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0};

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

void mutateKingAg()
{
    int gene;
    // mutate first phenotype
    gene = rand() % 2;
    kingAg[gene] = 1;
    kingAg[abs(gene - 1)] = 0;

    // mutate second phenotype
    gene = rand() % 4 + 2;
    // printf("mutateKingAg: %d\n", gene);

    kingAg[gene] = 1;
    checkPropertyMutation(gene);
    for (int i = 2; i < 6; i++)
    {
        if (i != gene)
            kingAg[i] = 0;
    }

    // mutate third phenotype
    gene = rand() % 3 + 6;
    kingAg[gene] = 1;
    checkPropertyMutation(gene);
    for (int i = 6; i < 9; i++)
    {
        if (i != gene)
            kingAg[i] = 0;
    }

    // mutate fourth phenotype
    gene = rand() % 2 + 9;
    kingAg[gene] = 1;
    kingAg[abs(gene - 19)] = 0;
}

void printArray(int *array)
{
    printf("%d ", kingAg[0]);
    printf("%d ", kingAg[1]);
    printf("| ");
    printf("%d ", kingAg[2]);
    printf("%d ", kingAg[3]);
    printf("%d ", kingAg[4]);
    printf("%d ", kingAg[5]);
    printf("| ");
    printf("%d ", kingAg[6]);
    printf("%d ", kingAg[7]);
    printf("%d ", kingAg[8]);
    printf("| ");
    printf("%d ", kingAg[9]);
    printf("%d ", kingAg[10]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    srand(42);
    printArray(kingAg);
    int i = 0;
    while (i++ < 1000)
    {
        mutateKingAg();
        printArray(kingAg);
    }
}
