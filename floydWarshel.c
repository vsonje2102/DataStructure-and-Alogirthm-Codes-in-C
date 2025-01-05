#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = graph[i][j];
        }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 0},
        {2, 0, 0, 0},
        {0, 7, 0, 1},
        {0, 0, 0, 0}
    };
    
    floydWarshall(graph);
    return 0;
}

