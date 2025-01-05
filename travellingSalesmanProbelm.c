#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int dist[MAX][MAX];
int visited[MAX];
int bestTour[MAX];
int minCost = INT_MAX;

int calculateLowerBound(int path[], int currentCity, int count) {
    int bound = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minDist = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && i != j) {
                    minDist = (dist[i][j] < minDist) ? dist[i][j] : minDist;
                }
            }
            bound += minDist;
        }
    }

    return bound;
}

void branchAndBound(int path[], int currentCost, int count) {
    if (count == n) {
        int lastCost = dist[path[count - 1]][path[0]];
        int totalCost = currentCost + lastCost;
        
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < n; i++) {
                bestTour[i] = path[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[count] = i;

            int lowerBound = calculateLowerBound(path, i, count + 1);
            if (currentCost + lowerBound < minCost) {
                branchAndBound(path, currentCost + dist[path[count - 1]][i], count + 1);
            }

            visited[i] = 0;
        }
    }
}

int main() {
    n = 4;

    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int path[MAX];
    visited[0] = 1;
    path[0] = 0;

    branchAndBound(path, 0, 1);

    printf("Optimal Tour: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestTour[i]);
    }
    printf("\nMinimum Cost: %d\n", minCost);

    return 0;
}

