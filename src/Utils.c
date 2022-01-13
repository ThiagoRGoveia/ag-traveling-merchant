#include "Includes.h"

void printArray(int *array)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void emptyOccupied()
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        occupied[i] = 0;
    }
}

void printPopulation()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        printf("Score: %lld: ", scores[i]);
        printArray(population[i]);
    }
}

void shuffle(int *array)
{
    for (int i = 0; i < NUM_NODES - 1; i++)
    {
        int j = i + lrand48() / (RAND_MAX / (NUM_NODES - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

void copyArray(int *source, int *destination)
{
    for (int i = 0; i < NUM_NODES; i++)
    {
        destination[i] = source[i];
    }
}

void populate()
{
    for (int i = 0; i < NUM_CHILDREN; i++)
    {
        shuffle(seedPath);
        copyArray(seedPath, population[i]);
    }
}

void createRandomPath(int *path)
{
    int found;
    for (int i = 0; i < NUM_NODES; i++)
    {
        while (1)
        {
            int randomNode = lrand48() % NUM_NODES;
            found = 0;
            for (int j = 0; j <= i; j++)
            {
                if (path[j] == randomNode)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                path[i] = randomNode;
                break;
            }
        }
    }
}

void saveBestOfAll(int *newBestOfAll, long long int bestScore, int currentGeneration)
{
    copyArray(newBestOfAll, bestOfAll);
    saveBestOfAllToFile(bestOfAll, bestScore, currentGeneration);
}

void saveBestOfAllToFile(int *newBestOfAll, long long int bestScore, int currentGeneration)
{
    // generation, score, path
    FILE *file;
    file = fopen(BEST_OF_ALL, "a");
    fprintf(file, "%d, ", currentGeneration);
    fprintf(file, "%lld, ", bestScore);
    for (int i = 0; i < NUM_NODES; i++)
    {
        fprintf(file, "%d ", newBestOfAll[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    // printf("%d, ", currentGeneration);
    // printf("%d, ", bestScore);
    // for (int i = 0; i < NUM_NODES; i++)
    // {
    //     printf("%d ", newBestOfAll[i]);
    // }
    // printf("\n");
}

void saveGenerationBestScore(int currentGeneration, long long int generationBestScore, int *generationBest)
{
    FILE *file;
    file = fopen(GENERATION_BEST_SCORE, "a");
    fprintf(file, "%d, ", currentGeneration);
    fprintf(file, "%lld, ", generationBestScore);
    // for (int i = 0; i < NUM_NODES; i++)
    // {
    //     fprintf(file, "%d ", generationBest[i]);
    // }
    fprintf(file, "\n");

    fclose(file);
    // printf("%d, ", currentGeneration);
    // printf("%d\n", generationBestScore);
}
