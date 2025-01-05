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

// Function to find the nearest unvisited city
int findNearestCity(int currentCity, int visited[]) {
    int minDist = INT_MAX;
    int nearestCity = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[currentCity][i] < minDist) {
            minDist = dist[currentCity][i];
            nearestCity = i;
        }
    }
    return nearestCity;
}

// Function to solve the TSP using a greedy approach
int tspGreedy() {
    int visited[N] = {0};  // Array to keep track of visited cities
    int totalDistance = 0;
    int currentCity = 0;   // Start from the first city
    visited[currentCity] = 1;
    int numVisited = 1;

    // Loop to visit all cities
    while (numVisited < N) {
        int nextCity = findNearestCity(currentCity, visited);
        visited[nextCity] = 1;
        totalDistance += dist[currentCity][nextCity];
        currentCity = nextCity;
        numVisited++;
    }

    // Return to the starting city
    totalDistance += dist[currentCity][0];

    return totalDistance;
}

int main() {
    int totalDistance = tspGreedy();
    printf("Total distance of the greedy TSP route: %d\n", totalDistance);
    return 0;
}

