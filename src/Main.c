#include "Includes.h"

void setup() {
    for (int i = 0; i < NUM_NODES; i++) {
        seedPath[i] = i;
        positionsArray[i] = i;
    }
}

int main()
{
    setup();
    unsigned short seed[3] = {155, 0, 155};

    // Initialize Seed Value For Random Number
    seed48(&seed[0]);
    populate();
    setupQueenPopulation();
    evolveQueenAg();
}