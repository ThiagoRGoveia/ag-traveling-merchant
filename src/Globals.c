#include "Includes.h"

int population[NUM_CHILDREN][NUM_NODES];
int scores[NUM_CHILDREN];
int occupied[NUM_NODES];
int bestOfAll[NUM_NODES];
int bestOfAllScore = INT_MAX;
int seedPath[NUM_NODES];
int positionsArray[NUM_NODES];
int numberOfGenerations = 300;
int currentGeneration = 0;