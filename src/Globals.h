#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "Includes.h"

extern int child[NUM_NODES];
extern int population[NUM_CHILDREN][NUM_NODES];
extern int scores[NUM_CHILDREN];
extern int occupied[NUM_NODES];
extern int bestOfAll[NUM_NODES];
extern int bestOfAllScore;
extern int seedPath[NUM_NODES];
extern int positionsArray[NUM_NODES];
extern int graph[NUM_NODES][NUM_NODES];
extern int completeGraph[NUM_NODES][NUM_NODES];
extern int currentGeneration;
extern int numberOfGenerations;
extern int graph[20][20];
extern int completeGraph[20][20];
extern int path[20][20][20];

#endif
