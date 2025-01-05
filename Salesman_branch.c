#include <stdio.h>
#include <limits.h>

#define N 5  // Number of cities

// Distance matrix representing the cities and their distances
int dist[N][N] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 5},
    {20, 25, 30, 0, 15},
    {25, 30, 5, 15, 0}
};

int minCost = INT_MAX;  // To store the minimum cost

// Function to calculate the lower bound of the cost for the current path
int calculateLowerBound(int path[], int n, int currCost, int visited[]) {
    int bound = currCost;

    // Find the two smallest edges for each vertex (except for the last one)
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int min1 = INT_MAX, min2 = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i != j && !visited[j]) {
                if (dist[i][j] < min1) {
                    min2 = min1;
                    min1 = dist[i][j];
                } else if (dist[i][j] < min2) {
                    min2 = dist[i][j];
                }
            }
        }

        bound += min1 + min2;
    }

    return bound;
}

// Function to perform the branch and bound approach for TSP
void tspBranchBound(int path[], int visited[], int level, int n, int currCost) {
    // If all cities have been visited, calculate the cost of returning to the start city
    if (level == n) {
        currCost += dist[path[n - 1]][path[0]];  // Return to the start city
        if (currCost < minCost) {
            minCost = currCost;  // Update the minimum cost
        }
        return;
    }

    // Calculate the lower bound for the current partial solution
    int bound = calculateLowerBound(path, n, currCost, visited);
    
    // If the bound is greater than or equal to the current best solution, prune the path
    if (bound >= minCost) return;

    // Explore the next level of paths
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            path[level] = i;  // Select the city to visit next
            visited[i] = 1;    // Mark city as visited

            tspBranchBound(path, visited, level + 1, n, currCost + dist[path[level - 1]][path[level]]); // Recur

            visited[i] = 0;  // Backtrack: unmark city as visited
        }
    }
}

int main() {
    int path[N];
    int visited[N] = {0};  // Array to mark visited cities
    visited[0] = 1;        // Start from city 0

    path[0] = 0;           // Start from city 0

    tspBranchBound(path, visited, 1, N, 0);

    printf("Minimum cost (Branch and Bound): %d\n", minCost);
    return 0;
}
//complexity O(n!)
