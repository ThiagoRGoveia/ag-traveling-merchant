#include "Includes.h"

// int queenAg[NUMBER_OF_QUEEN_AG_GENES] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0};
Gene bestQueenAg[NUMBER_OF_QUEEN_AG_GENES];
int bestGeneProperties[4];
int adaptedPositionBasedCrossover_numberOfPositions = 1;
int displacementMutation_subPathSize = 1;
int exchangeMutation_numberOfMutations = 1;
int insertionMutation_numberOfMutations = 1;
int bestQueenAgScore = INT_MAX;
int queenAgScores[QUEEN_AG_POPULATION_SIZE];
int queenAgGeneration = 0;
Gene queenAgPopulation[QUEEN_AG_POPULATION_SIZE][NUMBER_OF_QUEEN_AG_GENES];

void updateQueenAg(int newBestIndex)
{
    bestQueenAgScore = queenAgScores[newBestIndex];
    copyQueenAg(queenAgPopulation[newBestIndex], bestQueenAg);
    bestGeneProperties[0] = adaptedPositionBasedCrossover_numberOfPositions;
    bestGeneProperties[1] = displacementMutation_subPathSize;
    bestGeneProperties[2] = exchangeMutation_numberOfMutations;
    bestGeneProperties[3] = insertionMutation_numberOfMutations;
    // SAVE ON FILE
}

void copyQueenAg(Gene *source, Gene *destination)
{
    for (int i = 0; i < NUMBER_OF_QUEEN_AG_GENES; i++)
    {
        destination[i] = source[i];
    }
}

void mutateGene(Gene *gene)
{
    gene->mutationPower = rand() % MAX_MUTATION;
}

void mutateQueenAg(Gene *queenAg)
{
    int mutationChance = rand() % 1000;

    if (mutationChance < QUEEN_AG_FULL_MUTATION_TRESHOLD)
    {
        mutateQueenAgPhenotypes(queenAg);
    }
    else
    {
        mutateQueenAgGenes(queenAg);
    }
}

void mutateQueenAgGenes(Gene *queenAg)
{
    for (int i = 0; i < NUMBER_OF_QUEEN_AG_GENES; i++)
    {
        if (queenAg[i].isActive, queenAg[i].shouldMutateMutationPower)
        {
            mutateGene(&queenAg[i]);
        }
    }
}

void mutateQueenAgPhenotypes(Gene *queenAg)
{
    int gene;
    // mutate first phenotype
    gene = rand() % 2;
    queenAg[gene].isActive = 1;
    queenAg[abs(gene - 1)].isActive = 0;

    // mutate second phenotype
    gene = rand() % 4 + 2;

    queenAg[gene].isActive = 1;
    mutateGene(&queenAg[gene]);
    for (int i = 2; i < 6; i++)
    {
        if (i != gene)
            queenAg[i].isActive = 0;
    }

    // mutate third phenotype
    gene = rand() % 3 + 6;
    queenAg[gene].isActive = 1;
    mutateGene(&queenAg[gene]);
    for (int i = 6; i < 9; i++)
    {
        if (i != gene)
            queenAg[i].isActive = 0;
    }

    // mutate fourth phenotype
    gene = rand() % 2 + 9;
    queenAg[gene].isActive = 1;
    queenAg[abs(gene - 19)].isActive = 0;
}

int evaluateQueenAg()
{
    int localBestScore = INT_MAX;
    int localBestIndex = -1;
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        if (queenAgScores[i] < bestQueenAgScore)
        {
            localBestIndex = i;
            localBestScore = queenAgScores[i];
            updateQueenAg(i);
        }
        else if (queenAgScores[i] < localBestScore)
        {
            localBestIndex = i;
            localBestScore = queenAgScores[i];
        }
    }
    return localBestIndex;
}

void assexualReproduction(int generationBestIndex)
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        if (i == generationBestIndex)
            continue;
        copyQueenAg(queenAgPopulation[generationBestIndex], queenAgPopulation[i]);
        mutateQueenAg(queenAgPopulation[i]);
    }
}

void printQueenArray(Gene *queenAg)
{
    printf("%d ", queenAg[0].isActive);
    printf("%d ", queenAg[1].isActive);
    printf("| ");
    printf("%d ", queenAg[2].isActive);
    printf("%d ", queenAg[3].isActive);
    printf("%d ", queenAg[4].isActive);
    printf("%d ", queenAg[5].isActive);
    printf("| ");
    printf("%d ", queenAg[6].isActive);
    printf("%d ", queenAg[7].isActive);
    printf("%d ", queenAg[8].isActive);
    printf("| ");
    printf("%d ", queenAg[9].isActive);
    printf("%d ", queenAg[10].isActive);
    printf("\n");
}
void printScoresArray()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        printf("%d ", queenAgScores[i]);
    }
    printf("\n");
}

int evolveQueenAg()
{
    int i = 0;
    while (i++ < 3000)
    {
        queenAgGeneration++;
        for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
        {
            // queenAgScores[i] = evolveGraphAg(queenAgPopulation[i]);
            queenAgScores[i] = rand() % 1000;
        }
        int bestOfGenerationIndex = evaluateQueenAg();
        assexualReproduction(bestOfGenerationIndex);
    }
}

void populateQueenAgs()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        mutateQueenAg(queenAgPopulation[i]);
    }
}

void printQueenAgPopulation()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        printQueenArray(queenAgPopulation[i]);
    }
}

void configGene(Gene *gene, int isActive, int mutationPower, int shouldMutateMutationPower)
{
    gene->isActive = isActive;
    gene->mutationPower = mutationPower;
    gene->shouldMutateMutationPower = shouldMutateMutationPower;
}

void setupPopulation()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        configGene(&queenAgPopulation[i][0], 1, 0, 0);
        configGene(&queenAgPopulation[i][1], 0, 0, 0);
        configGene(&queenAgPopulation[i][2], 1, 1, 1);
        configGene(&queenAgPopulation[i][3], 0, 0, 0);
        configGene(&queenAgPopulation[i][4], 0, 0, 0);
        configGene(&queenAgPopulation[i][5], 0, 0, 0);
        configGene(&queenAgPopulation[i][6], 1, 1, 1);
        configGene(&queenAgPopulation[i][7], 0, 1, 1);
        configGene(&queenAgPopulation[i][8], 0, 1, 1);
        configGene(&queenAgPopulation[i][9], 0, 0, 0);
        configGene(&queenAgPopulation[i][10], 0, 0, 0);
    }
}

int main()
{
    srand(42);
    setupPopulation();
    populateQueenAgs();
    // evolveQueenAg();
    printQueenAgPopulation();
}
