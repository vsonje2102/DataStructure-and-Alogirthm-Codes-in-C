#include <stdio.h>
#include <stdlib.h>

#define MAX_SETS 5
#define MAX_ELEMENTS 6

// Define the sets and their sizes
int sets[MAX_SETS][MAX_ELEMENTS] = {
    {1, 2, 3, 4}, 
    {2, 3, 5}, 
    {1, 3, 6}, 
    {4, 5}, 
    {1, 2, 4, 5}
};

int setSizes[MAX_SETS] = {4, 3, 3, 2, 4}; // Number of elements in each set
int covered[MAX_ELEMENTS] = {0}; // Track if an element is covered

// Function to find the set that covers the most uncovered elements
int findBestSet() {
    int maxCover = 0;
    int bestSet = -1;

    for (int i = 0; i < MAX_SETS; i++) {
        int coverCount = 0;
        for (int j = 0; j < setSizes[i]; j++) {
            if (!covered[sets[i][j] - 1]) { // -1 for 0-based index
                coverCount++;
            }
        }

        if (coverCount > maxCover) {
            maxCover = coverCount;
            bestSet = i;
        }
    }
    return bestSet;
}

// Function to perform the set cover approximation
void setCover() {
    int selectedSets[MAX_SETS]; // To store selected sets
    int selectedCount = 0;

    while (1) {
        int bestSet = findBestSet();
        if (bestSet == -1) break; // All elements are covered

        // Mark the elements of the selected set as covered
        for (int i = 0; i < setSizes[bestSet]; i++) {
            covered[sets[bestSet][i] - 1] = 1; // Mark element as covered
        }

        selectedSets[selectedCount++] = bestSet; // Store selected set
    }

    // Print the selected sets
    printf("Selected sets: ");
    for (int i = 0; i < selectedCount; i++) {
        printf("%d ", selectedSets[i] + 1); // +1 for 1-based indexing
    }
    printf("\n");
}

int main() {
    setCover();
    return 0;
}
//compelxity O(n*m) where n is no of sets and m is no os elements in each set

