#ifndef AGTORULETHEMALL_H_
#define AGTORULETHEMALL_H_

#include "Includes.h"

#define ELITISM 0
#define TOURNAMENT 1
#define ADAPTED_POSITION_BASED_CROSSOVER 2
#define ALTERNATING_POSITIONS_CROSSOVER 3
#define MAXIMAL_PRESERVATIVE_CROSSOVER 4
#define NO_CROSSOVER 5
#define DISPLACEMENT_MUTATION 6
#define EXCHANGE_MUTATION 7
#define INSERTION_MUTATION 8
#define PREDATION 9
#define GENOCIDE 10
#define NUMBER_OF_QUEEN_AG_GENES 11
#define NUMBER_OF_QUEEN_AG_GENES_EXCLUDING_GENOCIDE 10
#define MAX_MUTATION (NUM_NODES / 2)
#define QUEEN_AG_POPULATION_SIZE 50
#define QUEEN_AG_FULL_MUTATION_TRESHOLD 200
#define GENOCIDE_THRESHOLD 100
#define PREDATION_THRESHOLD 600

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
void mutateGene(Gene *gene);
void mutateQueenAg(Gene *queenAg);
void mutateQueenAgGenes(Gene *queenAg);
void mutateQueenAgPhenotypes(Gene *queenAg);
int evaluateQueenAg();
void assexualReproduction(int generationBestIndex);
void printQueenAgPopulation();
void populateQueenAgs();
void printQueenAgPopulation();
void configGene(Gene *gene, int isActive, int mutationPower, int shouldMutateMutationPower);
void setupPopulation();
void saveBestQueenAgToFile();

#endif
