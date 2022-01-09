#include "Includes.h"

// void setup() {}

int main()
{
    srand(RANDOM_SEED);
    // Gene queenAg[NUMBER_OF_QUEEN_AG_GENES];
    // configGene(&queenAg[0], 1, 0, 0);
    // configGene(&queenAg[1], 0, 0, 0);
    // configGene(&queenAg[2], 0, 1, 2);
    // configGene(&queenAg[3], 0, 0, 0);
    // configGene(&queenAg[4], 0, 5, 1);
    // configGene(&queenAg[5], 1, 0, 0);
    // configGene(&queenAg[6], 0, 5, 1);
    // configGene(&queenAg[7], 0, 5, 1);
    // configGene(&queenAg[8], 1, 5, 1);
    // configGene(&queenAg[9], 0, 0, 0);
    // configGene(&queenAg[10], 0, 0, 0);

    populate();
    setupQueenPopulation();
    evolveQueenAg();
}