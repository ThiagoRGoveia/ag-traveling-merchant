#include "Includes.h"

// int queenAg[NUMBER_OF_QUEEN_AG_GENES] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0};
Gene bestQueenAg[NUMBER_OF_QUEEN_AG_GENES];
int bestGeneProperties[4];
int bestQueenAgScore = INT_MAX;
int queenAgScores[QUEEN_AG_POPULATION_SIZE];
int queenAgGeneration = 0;
Gene queenAgPopulation[QUEEN_AG_POPULATION_SIZE][NUMBER_OF_QUEEN_AG_GENES];

void updateQueenAg(int newBestIndex)
{
    bestQueenAgScore = queenAgScores[newBestIndex];
    copyQueenAg(queenAgPopulation[newBestIndex], bestQueenAg);
    saveBestQueenAgToFile();
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
    gene = rand() % 1000;
    if (gene < GENOCIDE_THRESHOLD)
    {
        queenAg[GENOCIDE].isActive = 1;
        queenAg[PREDATION].isActive = 0;
    }
    else if (gene < PREDATION_THRESHOLD)
    {
        queenAg[GENOCIDE].isActive = 0;
        queenAg[PREDATION].isActive = 1;
    }
    else
    {
        queenAg[GENOCIDE].isActive = 0;
        queenAg[PREDATION].isActive = 0;
    }
}

int evaluateQueenAg()
{
    int localBestScore = INT_MAX;
    int localBestIndex = -1;
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        // printf("Evaluating queenAg %d\n", i);
        // printf("%d, %d", queenAgScores[i], bestQueenAgScore);
        if (queenAgScores[i] < bestQueenAgScore)
        {
            printf("New best score: %d\n", queenAgScores[i]);
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
    printf("%d, ", queenAg[10].isActive);
    printf("%d ", queenAg[0].mutationPower);
    printf("%d ", queenAg[1].mutationPower);
    printf("| ");
    printf("%d ", queenAg[2].mutationPower);
    printf("%d ", queenAg[3].mutationPower);
    printf("%d ", queenAg[4].mutationPower);
    printf("%d ", queenAg[5].mutationPower);
    printf("| ");
    printf("%d ", queenAg[6].mutationPower);
    printf("%d ", queenAg[7].mutationPower);
    printf("%d ", queenAg[8].mutationPower);
    printf("| ");
    printf("%d ", queenAg[9].mutationPower);
    printf("%d ", queenAg[10].mutationPower);
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
    // int i = 0;
    while (1)
    {
        assexualReproduction(0);
        printQueenAgPopulation();
        // DESCOMENTAR DEPOIS
        queenAgGeneration++;
        printf("Generation: %d\n", queenAgGeneration);
        for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
        {
            printf("Evaluating queenAg %d\n", i);
            queenAgScores[i] = evolveGraphAg(queenAgPopulation[i]);
            // queenAgScores[i] = rand() % 1000;
        }
        // print scores
        printScoresArray();
        int bestOfGenerationIndex = evaluateQueenAg();
        printf("Best of generation id: %d score: %d\n", bestOfGenerationIndex, queenAgScores[bestOfGenerationIndex]);
        saveGenerationQueenAgBestScore(queenAgGeneration, queenAgScores[bestOfGenerationIndex]);
        printQueenAgPopulation();
        assexualReproduction(bestOfGenerationIndex);
        printQueenAgPopulation();
        numberOfGenerations += 50;
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
        print("(%d) ", i);
        printQueenArray(queenAgPopulation[i]);
    }
}

void configGene(Gene *gene, int isActive, int mutationPower, int shouldMutateMutationPower)
{
    gene->isActive = isActive;
    gene->mutationPower = mutationPower;
    gene->shouldMutateMutationPower = shouldMutateMutationPower;
}

void setupQueenPopulation()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        configGene(&queenAgPopulation[i][0], 1, 0, 0);
        configGene(&queenAgPopulation[i][1], 0, 0, 0);
        configGene(&queenAgPopulation[i][2], 0, 1, 1);
        configGene(&queenAgPopulation[i][3], 0, 0, 0);
        configGene(&queenAgPopulation[i][4], 1, 5, 1);
        configGene(&queenAgPopulation[i][5], 0, 0, 0);
        configGene(&queenAgPopulation[i][6], 1, 2, 1);
        configGene(&queenAgPopulation[i][7], 0, 2, 1);
        configGene(&queenAgPopulation[i][8], 0, 2, 1);
        configGene(&queenAgPopulation[i][9], 0, 0, 0);
        configGene(&queenAgPopulation[i][10], 0, 0, 0);
    }
}

void saveGenerationQueenAgBestScore(int currentGeneration, int generationBestScore)
{
    FILE *file;
    file = fopen(GENERATION_QUEEN_AG_BEST_SCORE, "a");
    fprintf(file, "%d, ", currentGeneration);
    fprintf(file, "%d, ", generationBestScore);
    fprintf(file, "%d, %d, ", queenAgGeneration, bestQueenAgScore);
    fprintf(file, "%d ", bestQueenAg[0].isActive);
    fprintf(file, "%d ", bestQueenAg[1].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[2].isActive);
    fprintf(file, "%d ", bestQueenAg[3].isActive);
    fprintf(file, "%d ", bestQueenAg[4].isActive);
    fprintf(file, "%d ", bestQueenAg[5].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[6].isActive);
    fprintf(file, "%d ", bestQueenAg[7].isActive);
    fprintf(file, "%d ", bestQueenAg[8].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[9].isActive);
    fprintf(file, "%d, ", bestQueenAg[10].isActive);
    fprintf(file, "%d ", bestQueenAg[0].mutationPower);
    fprintf(file, "%d ", bestQueenAg[1].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[2].mutationPower);
    fprintf(file, "%d ", bestQueenAg[3].mutationPower);
    fprintf(file, "%d ", bestQueenAg[4].mutationPower);
    fprintf(file, "%d ", bestQueenAg[5].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[6].mutationPower);
    fprintf(file, "%d ", bestQueenAg[7].mutationPower);
    fprintf(file, "%d ", bestQueenAg[8].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[9].mutationPower);
    fprintf(file, "%d ", bestQueenAg[10].mutationPower);
    fprintf(file, "\n");
    fclose(file);
    // printf("%d, ", currentGeneration);
    // printf("%d\n", generationBestScore);
}

void saveBestQueenAgToFile()
{
    // generation, score, ag
    printf("SAVING BEST QUEEN AG TO FILE\n");
    FILE *file = fopen(BEST_QUEEN_AG, "a");
    fprintf(file, "%d, %d, ", queenAgGeneration, bestQueenAgScore);
    fprintf(file, "%d ", bestQueenAg[0].isActive);
    fprintf(file, "%d ", bestQueenAg[1].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[2].isActive);
    fprintf(file, "%d ", bestQueenAg[3].isActive);
    fprintf(file, "%d ", bestQueenAg[4].isActive);
    fprintf(file, "%d ", bestQueenAg[5].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[6].isActive);
    fprintf(file, "%d ", bestQueenAg[7].isActive);
    fprintf(file, "%d ", bestQueenAg[8].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[9].isActive);
    fprintf(file, "%d, ", bestQueenAg[10].isActive);
    fprintf(file, "%d ", bestQueenAg[0].mutationPower);
    fprintf(file, "%d ", bestQueenAg[1].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[2].mutationPower);
    fprintf(file, "%d ", bestQueenAg[3].mutationPower);
    fprintf(file, "%d ", bestQueenAg[4].mutationPower);
    fprintf(file, "%d ", bestQueenAg[5].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[6].mutationPower);
    fprintf(file, "%d ", bestQueenAg[7].mutationPower);
    fprintf(file, "%d ", bestQueenAg[8].mutationPower);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[9].mutationPower);
    fprintf(file, "%d ", bestQueenAg[10].mutationPower);
    fprintf(file, "\n");
    fclose(file);
}

// int main()
// {
//     srand(42);
//     setupQueenPopulation();
//     populateQueenAgs();
//     evolveQueenAg();
//     printQueenAgPopulation();
// }
