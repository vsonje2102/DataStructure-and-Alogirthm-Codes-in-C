#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int dist[MAX_CITIES][MAX_CITIES];
int n;

int calculateTourCost(int tour[]) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += dist[tour[i]][tour[i + 1]];
    }
    cost += dist[tour[n - 1]][tour[0]];  // Returning to the starting city
    return cost;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int tour[], int l, int r, int *minCost, int bestTour[]) {
    if (l == r) {
        int cost = calculateTourCost(tour);
        if (cost < *minCost) {
            *minCost = cost;
            for (int i = 0; i < n; i++) {
                bestTour[i] = tour[i];
            }
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(&tour[l], &tour[i]);
            permute(tour, l + 1, r, minCost, bestTour);
            swap(&tour[l], &tour[i]);  // backtrack
        }
    }
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

    // Array representing the cities
    int tour[MAX_CITIES];
    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }

    int minCost = INT_MAX;
    int bestTour[MAX_CITIES];
    permute(tour, 0, n - 1, &minCost, bestTour);

    printf("Optimal Tour: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestTour[i]);
    }
    printf("\nTotal Cost: %d\n", minCost);

    return 0;
}

