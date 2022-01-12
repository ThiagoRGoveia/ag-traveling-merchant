#include "Includes.h"
// int graph[NUM_NODES][NUM_NODES];
int completeGraph[NUM_NODES][NUM_NODES];

void readGraph()
{
    FILE *fp;
    int graph_size;
    fp = fopen(GRAPH_FILE_PATH, "r");
    fread(&graph_size, sizeof(int), 1, fp);
    printf("Graph size: %d\n", graph_size);
    for (int i = 0; i < NUM_NODES; i++)
    {
        for (int j = 0; j < NUM_NODES; j++)
        {
            fread(&completeGraph[i][j], sizeof(int), 1, fp);
        }
    }
}


int main()
{
    // readGraph();
    // for (int i = 0; i < NUM_NODES; i++)
    // {
    //     for (int j = 0; j < NUM_NODES; j++)
    //     {
    //         if (j == NUM_NODES - 1)
    //             printf("%d", graph[i][j]);
    //         else
    //         {
    //             printf("%d,", graph[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
    long int a = INT_MAX;
    printf("%ld\n", a);
    a = a + 1;
    printf("%ld\n", a);
}