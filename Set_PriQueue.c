#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SETS 5
#define MAX_ELEMENTS 6

int sets[MAX_SETS][MAX_ELEMENTS] = {
    {1, 2, 3, 4},
    {2, 3, 5},
    {1, 3, 6},
    {4, 5},
    {1, 2, 4, 5}
};

int setSizes[MAX_SETS] = {4, 3, 3, 2, 4}; // Number of elements in each set
int elements[MAX_ELEMENTS] = {1, 2, 3, 4, 5, 6}; // All elements to cover

// Function to calculate the number of uncovered elements in a set
int uncoveredElementsCount(int set[], int setSize, bool covered[]) {
    int count = 0;
    for (int i = 0; i < setSize; i++) {
        if (!covered[set[i] - 1]) { // If element is not covered
            count++;
        }
    }
    return count;
}

// Function to perform the set cover approximation using a greedy strategy
void setCover() {
    bool covered[MAX_ELEMENTS] = {0}; // Track if an element is covered
    bool selected[MAX_SETS] = {0};    // Track if a set is selected
    int selectedSets[MAX_SETS];        // To store selected sets
    int selectedCount = 0;

    // Select sets until all elements are covered
    while (1) {
        int bestSet = -1;
        int maxCover = 0;
        
        // Find the set that covers the maximum number of uncovered elements
        for (int i = 0; i < MAX_SETS; i++) {
            if (selected[i]) continue; // Skip already selected sets
            int uncoveredCount = uncoveredElementsCount(sets[i], setSizes[i], covered);
            if (uncoveredCount > maxCover) {
                maxCover = uncoveredCount;
                bestSet = i;
            }
        }

        // If no set is found to cover any element, break
        if (bestSet == -1) break;

        // Mark the elements of the selected set as covered
        for (int i = 0; i < setSizes[bestSet]; i++) {
            covered[sets[bestSet][i] - 1] = 1; // Mark element as covered
        }

        selectedSets[selectedCount++] = bestSet; // Store selected set
        selected[bestSet] = 1; // Mark set as selected
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
//O(n*m)
