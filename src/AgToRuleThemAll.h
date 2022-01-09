#ifndef AGTORULETHEMALL_H_
#define AGTORULETHEMALL_H_

#include "Includes.h"

typedef struct
{
    int isActive;
    int mutationPower;
    int shouldMutateMutationPower;
} Gene;

extern Gene queenAg[NUMBER_OF_QUEEN_AG_GENES];
extern Gene queenAgPopulation[QUEEN_AG_POPULATION_SIZE][NUMBER_OF_QUEEN_AG_GENES];
extern int queenAgScores[QUEEN_AG_POPULATION_SIZE];
extern int bestKinAgIndex;
extern int bestQueenAgScore;

void updateQueenAg(int newBestIndex);
void copyQueenAg(Gene *source, Gene *destination);
void mutateGene(Gene *gene, int score);
void mutateQueenAg(Gene *queenAg, int score);
void mutateQueenAgGenes(Gene *queenAg, int score);
void mutateQueenAgPhenotypes(Gene *queenAg, int score);
int evaluateQueenAg();
void assexualReproduction(int generationBestIndex);
void printQueenAgPopulation();
void populateQueenAgs();
void printQueenAgPopulation();
void configGene(Gene *gene, int isActive, int mutationPower, int shouldMutateMutationPower);
void setupQueenPopulation();
void saveBestQueenAgToFile();
void saveGenerationQueenAgBestScore(int currentGeneration, int generationBestScore);
int evolveQueenAg();

#endif
