#include <stdio.h>
#include <stdbool.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

bool isSafe(int v, int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int color[], int m, int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c;
            if (graphColoringUtil(color, m, v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int m) {
    int color[V] = {0};
    
    if (graphColoringUtil(color, m, 0)) {
        printf("Solution exists: The color assignment is:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
        return true;
    }

    printf("Solution does not exist.\n");
    return false;
}

int main() {
    int m = 4;
    if (!graphColoring(m)) {
        printf("Solution not found with %d colors.\n", m);
    }
    return 0;
}

