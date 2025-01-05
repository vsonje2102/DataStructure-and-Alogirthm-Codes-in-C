#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(int graph[V][V]) {
    Edge edges[E];
    int k = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    qsort(edges, E, sizeof(Edge), compare);

    Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int x = find(subsets, u);
        int y = find(subsets, v);

        if (x != y) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            unionSets(subsets, x, y);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 5, 0},
        {3, 0, 4, 7, 6},
        {0, 4, 0, 0, 8},
        {5, 7, 0, 0, 2},
        {0, 6, 8, 2, 0}
    };

    kruskalMST(graph);
    return 0;
}

//time complexity O(E log E) where E is no of edges
