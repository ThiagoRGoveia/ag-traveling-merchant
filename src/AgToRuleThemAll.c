#include "Includes.h"

// int queenAg[NUMBER_OF_QUEEN_AG_GENES] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0};
Gene bestQueenAg[NUMBER_OF_QUEEN_AG_GENES];
int bestGeneProperties[4];
long long int bestQueenAgScore = INT_MAX;
int bestQueenAgGeneration = 0;
long long int queenAgScores[QUEEN_AG_POPULATION_SIZE] = {0};
int queenAgGeneration = 0;
Gene queenAgPopulation[QUEEN_AG_POPULATION_SIZE][NUMBER_OF_QUEEN_AG_GENES];

void updateQueenAg(int newBestIndex)
{
    bestQueenAgScore = queenAgScores[newBestIndex];
    bestQueenAgGeneration = queenAgGeneration;
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
    if ((queenAgGeneration - bestQueenAgGeneration) < 100 && gene->mutationPower < MAX_MUTATION)
    {
        gene->mutationPower++;
    }
    else if ((queenAgGeneration - bestQueenAgGeneration) > 100 && gene->mutationPower > MIN_MUTATION)
    {
        gene->mutationPower--;
    }
}

void mutateQueenAg(Gene *queenAg)
{
    int mutationChance = lrand48() % 1000;

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
    // gene = lrand48() % 2;
    // queenAg[gene].isActive = 1;
    // queenAg[abs(gene - 1)].isActive = 0;
    // gene = lrand48() % 1000;
    // if (gene <= 200)
    // {
    //     queenAg[ELITISM].isActive = 0;
    //     queenAg[TOURNAMENT].isActive = 1;
    // }
    // else
    // {
    //     queenAg[ELITISM].isActive = 1;
    //     queenAg[TOURNAMENT].isActive = 0;
    // }

    // mutate second phenotype
    gene = lrand48() % 3 + 2;

    queenAg[gene].isActive = 1;
    mutateGene(&queenAg[gene]);
    for (int i = 2; i < 5; i++)
    {
        if (i != gene)
            queenAg[i].isActive = 0;
    }

    // mutate third phenotype
    gene = lrand48() % 3 + 5;
    queenAg[gene].isActive = 1;
    mutateGene(&queenAg[gene]);
    for (int i = 5; i < 8; i++)
    {
        if (i != gene)
            queenAg[i].isActive = 0;
    }

    // mutate fourth phenotype
    gene = lrand48() % 1000;
    if (gene < GENOCIDE_THRESHOLD)
    {
        queenAg[GENOCIDE].isActive = 0;
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
    printf("| ");
    printf("%d ", queenAg[5].isActive);
    printf("%d ", queenAg[6].isActive);
    printf("%d ", queenAg[7].isActive);
    printf("| ");
    printf("%d ", queenAg[8].isActive);
    printf("%d ", queenAg[9].isActive);
    // printf("%d, ", queenAg[10].isActive);
    printf("|| %d ", queenAg[0].mutationPower);
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
    // printf("%d ", queenAg[10].mutationPower);
    printf("\n");
}
void printScoresArray()
{
    for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
    {
        printf("%lld ", queenAgScores[i]);
    }
    printf("\n");
}

int evolveQueenAg()
{
    assexualReproduction(0);
    while (1)
    {
        queenAgGeneration++;
        printf("Generation: %d\n", queenAgGeneration);
        for (int i = 0; i < QUEEN_AG_POPULATION_SIZE; i++)
        {
            queenAgScores[i] = evolveGraphAg(queenAgPopulation[i]);
        }
        int bestOfGenerationIndex = evaluateQueenAg();
        saveGenerationQueenAgBestScore(queenAgGeneration, queenAgScores[bestOfGenerationIndex]);
        assexualReproduction(bestOfGenerationIndex);
        // numberOfGenerations += 50;
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
        printf("(%d) ", i);
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
        configGene(&queenAgPopulation[i][ELITISM], 1, 0, 0);
        configGene(&queenAgPopulation[i][TOURNAMENT], 0, 0, 0);
        configGene(&queenAgPopulation[i][ALTERNATING_POSITIONS_CROSSOVER], 1, 0, 0);
        configGene(&queenAgPopulation[i][MAXIMAL_PRESERVATIVE_CROSSOVER], 0, 0, 0);
        configGene(&queenAgPopulation[i][NO_CROSSOVER], 0, 0, 0);
        configGene(&queenAgPopulation[i][DISPLACEMENT_MUTATION], 1, 2, 1);
        configGene(&queenAgPopulation[i][EXCHANGE_MUTATION], 0, 5, 1);
        configGene(&queenAgPopulation[i][INSERTION_MUTATION], 0, 2, 1);
        configGene(&queenAgPopulation[i][PREDATION], 0, 0, 0);
        configGene(&queenAgPopulation[i][GENOCIDE], 0, 0, 0);
    }
}

void saveGenerationQueenAgBestScore(int currentGeneration, int generationBestScore)
{
    FILE *file;
    file = fopen(GENERATION_QUEEN_AG_BEST_SCORE, "a");
    fprintf(file, "%d, ", currentGeneration);
    fprintf(file, "%d, ", generationBestScore);
    // fprintf(file, "%d ", bestQueenAg[0].isActive);
    // fprintf(file, "%d ", bestQueenAg[1].isActive);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[2].isActive);
    // fprintf(file, "%d ", bestQueenAg[3].isActive);
    // fprintf(file, "%d ", bestQueenAg[4].isActive);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[5].isActive);
    // fprintf(file, "%d ", bestQueenAg[6].isActive);
    // fprintf(file, "%d ", bestQueenAg[7].isActive);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[8].isActive);
    // fprintf(file, "%d ", bestQueenAg[9].isActive);
    // fprintf(file, "|| %d ", bestQueenAg[0].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[1].mutationPower);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[2].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[3].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[4].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[5].mutationPower);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[6].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[7].mutationPower);
    // fprintf(file, "%d ", bestQueenAg[8].mutationPower);
    // fprintf(file, "| ");
    // fprintf(file, "%d ", bestQueenAg[9].mutationPower);
    fprintf(file, "\n");
    fclose(file);
}

void saveBestQueenAgToFile()
{
    // generation,, ag
    // printf("SAVING BEST QUEEN AG TO FILE\n");
    FILE *file = fopen(BEST_QUEEN_AG, "a");
    fprintf(file, "%d, %lld, ", queenAgGeneration, bestQueenAgScore);
    fprintf(file, "%d ", bestQueenAg[0].isActive);
    fprintf(file, "%d ", bestQueenAg[1].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[2].isActive);
    fprintf(file, "%d ", bestQueenAg[3].isActive);
    fprintf(file, "%d ", bestQueenAg[4].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[5].isActive);
    fprintf(file, "%d ", bestQueenAg[6].isActive);
    fprintf(file, "%d ", bestQueenAg[7].isActive);
    fprintf(file, "| ");
    fprintf(file, "%d ", bestQueenAg[8].isActive);
    fprintf(file, "%d ", bestQueenAg[9].isActive);
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
    fprintf(file, "\n");
    fclose(file);
}

// int main()
// {
//     slrand48(42);
//     setupQueenPopulation();
//     populateQueenAgs();
//     evolveQueenAg();
//     printQueenAgPopulation();
// }
