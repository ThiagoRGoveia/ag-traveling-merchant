#ifndef AGTORULETHEMALL_H_
#define AGTORULETHEMALL_H_

#include "Includes.h"

#define ELITISM 0
#define TOURNAMENT 1
#define ADAPTEDPOSITIONBASEDCROSSOVER 2
#define ALTERNATINGPOSITIONSCROSSOVER 3
#define MAXIMALPRESERVATIVECROSSOVER 4
#define DISPLACEMENTMUTATION 5
#define EXCHANGEMUTATION 6
#define INSERTIONMUTATION 7
#define PREDATION 8
#define GENOCIDE 9
#define NUMBER_OF_KING_AG_GENES 10
#define NUMBER_OF_KING_AG_GENES_EXCLUDING_GENOCIDE 9

#define MAX_MUTATION (NUM_NODES / 2)

extern int adaptedPositionBasedCrossover_numberOfPositions;
extern int displacementMutation_subPathSize;
extern int exchangeMutation_numberOfMutations;
extern int insertionMutation_numberOfMutations;

#endif
