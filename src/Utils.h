#ifndef UTILS_H_
#define UTILS_H_

void emptyOccupied();
void printPopulation();
void copyArray(int *source, int *destination);
void shuffle(int *array);
void printArray(int *array);
void populate();
void createRandomPath(int *path);
void saveBestOfAll(int *newBestOfAll, long long int bestScore, int currentGeneration);
void saveBestOfAllToFile(int *newBestOfAll, long long int bestScore, int currentGeneration);
void saveGenerationBestScore(int currentGeneration, long long int generationBestScore, int *generationBest);

#endif
