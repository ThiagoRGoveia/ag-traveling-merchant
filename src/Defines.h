#ifndef DEFINES_H_
#define DEFINES_H_

// Configs
#define NUM_NODES 1000
#define NUM_CHILDREN 100
#define INITIAL_MUTATION_RATE 1

// Paths
#define BEST_QUEEN_AG "./src/output/bestQueenAg_1000_100.csv"
#define GENERATION_QUEEN_AG_BEST_SCORE "./src/output/generationQueenBestScore_1000_100.csv"
#define BEST_OF_ALL "./src/output/bestOfAll_1000_100.csv"
#define GENERATION_BEST_SCORE "./src/output/generationBestScore_1000_100.csv"

#define ELITISM 0
#define TOURNAMENT 1
#define ALTERNATING_POSITIONS_CROSSOVER 2
#define MAXIMAL_PRESERVATIVE_CROSSOVER 3
#define NO_CROSSOVER 4
#define DISPLACEMENT_MUTATION 5
#define EXCHANGE_MUTATION 6
#define INSERTION_MUTATION 7
#define PREDATION 8
#define GENOCIDE 9
#define NUMBER_OF_QUEEN_AG_GENES 10
#define NUMBER_OF_QUEEN_AG_GENES_EXCLUDING_GENOCIDE 9
#define ADAPTED_POSITION_BASED_CROSSOVER -1

#define MAX_MUTATION (NUM_NODES / 4)
#define MIN_MUTATION 2
#define ERROR_THRESHOLD 50
#define QUEEN_AG_POPULATION_SIZE 50
#define QUEEN_AG_FULL_MUTATION_TRESHOLD 800
#define GENOCIDE_THRESHOLD 100
#define PREDATION_THRESHOLD 600

#endif
