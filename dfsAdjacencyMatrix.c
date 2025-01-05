#include <stdio.h>

#define V 5

void dfsMatrix(int graph[V][V], int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfsMatrix(graph, visited, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int visited[V] = {0};
    printf("DFS (Adjacency Matrix): ");
    dfsMatrix(graph, visited, 0);
    printf("\n");
    return 0;
}

