// Source: Adaptado de https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include "Includes.h"
#include <stdbool.h>

#define SIZE 500

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < SIZE; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void saveToGraph(int dist[], int i)
{
    for (int j = 0; j < SIZE; j++)
    {
        completeGraph[i][j] = dist[j];
    }
}

void printSolution(int dist[])
{
    printf("{");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE)
        {
            printf("%d", dist[i]);
        }
        else
        {
            printf("%d, ", dist[i]);
        }
    }
    printf("},\n");
}

void dijkstra(int graph[NUM_NODES][NUM_NODES], int src)
{
    int dist[SIZE]; // The output array. dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[SIZE]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < SIZE; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < SIZE - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < SIZE; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    // saveToGraph(dist, src);
    printSolution(dist);
}

int runDijkstra()
{
    for (int i = 0; i < SIZE; i++)
    {
        dijkstra(graph, i);
    }
    return 0;
}
