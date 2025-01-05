#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false; // If adjacent vertex has the same color, return false
        }
    }
    return true;
}

// Function to assign colors to the vertices of the graph
void graphColoring(int graph[V][V]) {
    int color[V]; // Array to store the color assigned to each vertex

    // Initially, all vertices are assigned no color (-1)
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    // Assign color to the first vertex
    color[0] = 0;

    // Assign colors to the remaining vertices
    for (int v = 1; v < V; v++) {
        // Try all colors one by one
        for (int c = 0; c < V; c++) {
            if (isSafe(graph, color, v, c)) {
                color[v] = c; // Assign color c to vertex v
                break;
            }
        }
    }

    // Print the color assigned to each vertex
    printf("Vertex   Color\n");
    for (int i = 0; i < V; i++) {
        printf("%d        %d\n", i, color[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    graphColoring(graph);
    return 0;
}
//time complexity O(V^2)
