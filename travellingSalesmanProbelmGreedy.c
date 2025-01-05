#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int dist[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int n;  // Number of cities

int greedyTSP(int start) {
    int total_cost = 0;
    int current_city = start;
    visited[current_city] = 1;
    int count = 1;
    
    while (count < n) {
        int min_dist = INT_MAX;
        int next_city = -1;
        
        // Find the nearest unvisited city
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[current_city][i] < min_dist) {
                min_dist = dist[current_city][i];
                next_city = i;
            }
        }
        
        // Move to the nearest city
        visited[next_city] = 1;
        total_cost += min_dist;
        current_city = next_city;
        count++;
    }

    // Return to the start city
    total_cost += dist[current_city][start];
    return total_cost;
}

int main() {
    n = 4;  // Number of cities
    int start = 0;  // Starting city

    // Distance matrix between cities
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Copy graph to dist matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Initialize visited array to 0 (not visited)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int total_cost = greedyTSP(start);
    printf("Total Cost of Greedy TSP: %d\n", total_cost);
    
    return 0;
}

