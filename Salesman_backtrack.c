#include <stdio.h>
#include <limits.h>

#define N 5  // Number of cities

int dist[N][N] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 5},
    {20, 25, 30, 0, 15},
    {25, 30, 5, 15, 0}
};

int visited[N];  // Array to keep track of visited cities
int minCost = INT_MAX;  // Variable to store the minimum cost

int calculateCost(int path[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n - 1; i++) {
        totalCost += dist[path[i]][path[i + 1]];
    }
    totalCost += dist[path[n - 1]][path[0]];  
    return totalCost;
}

void tspBacktracking(int path[], int level, int n) {
    if (level == n) {
        int cost = calculateCost(path, n);
        if (cost < minCost) {
            minCost = cost;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            path[level] = i;  
            visited[i] = 1;    

            tspBacktracking(path, level + 1, n);  

            visited[i] = 0;  
        }
    }
}

int main() {
    int path[N];
    for (int i = 0; i < N; i++) visited[i] = 0;
    
    visited[0] = 1; 
    path[0] = 0;     

    tspBacktracking(path, 1, N);

    printf("Minimum cost (Backtracking): %d\n", minCost);
    return 0;
}
//time complexity O(n!)
