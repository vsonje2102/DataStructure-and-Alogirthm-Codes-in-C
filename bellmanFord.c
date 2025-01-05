#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5
#define E 8

typedef struct {
    int src, dest, weight;
} Edge;

void bellmanFord(Edge edges[], int V, int E, int src) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d        INF\n", i);
        } else {
            printf("%d        %d\n", i, dist[i]);
        }
    }
}

int main() {
    Edge edges[E] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {2, 3, 5}, {2, 4, 1}, {3, 4, -3}
    };

    int source = 0;
    bellmanFord(edges, V, E, source);

    return 0;
}

