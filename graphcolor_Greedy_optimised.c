#include <stdio.h>
#include <stdlib.h>

#define V 5

// Adjacency list representation of the graph
int graph[V][V] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

// Function to find the color for a vertex
int getAvailableColor(int vertex, int color[], int graph[V][V]) {
    int availableColor = 0;
    
    // Check colors of adjacent vertices
    while (availableColor < V) {
        int valid = 1;
        for (int i = 0; i < V; i++) {
            if (graph[vertex][i] == 1 && color[i] == availableColor) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            return availableColor;
        }
        availableColor++;
    }
    return availableColor;
}

// Function to color the graph
void greedyColoring(int graph[V][V]) {
    int color[V];  // Array to store the color of each vertex
    for (int i = 0; i < V; i++) {
        color[i] = -1;  // Initially, no vertex has a color
    }

    // Assign color to the first vertex
    color[0] = 0;

    // Assign colors to remaining vertices
    for (int u = 1; u < V; u++) {
        color[u] = getAvailableColor(u, color, graph);
    }

    // Print the result
    printf("Vertex   Color\n");
    for (int i = 0; i < V; i++) {
        printf("%d        %d\n", i, color[i]);
    }
}

int main() {
    greedyColoring(graph);
    return 0;
}
//time complexity O(V+E)
