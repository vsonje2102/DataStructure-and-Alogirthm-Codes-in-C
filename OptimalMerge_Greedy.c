#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
} File;

// Min-heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void insertHeap(int arr[], int* n, int val) {
    arr[*n] = val;
    (*n)++;
    for (int i = (*n - 1) / 2; i >= 0; i--)
        minHeapify(arr, *n, i);
}

int extractMin(int arr[], int* n) {
    if (*n <= 0)
        return -1;

    if (*n == 1) {
        (*n)--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);

    return root;
}

// Optimal merge pattern function
int optimalMergeCost(int sizes[], int n) {
    int totalCost = 0;

    // Build the min-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(sizes, n, i);

    while (n > 1) {
        // Extract the two smallest files
        int min1 = extractMin(sizes, &n);
        int min2 = extractMin(sizes, &n);

        // The cost of merging the two files
        int mergeCost = min1 + min2;
        totalCost += mergeCost;

        // Insert the merged file back into the heap
        insertHeap(sizes, &n, mergeCost);
    }

    return totalCost;
}

int main() {
    int sizes[] = {4, 3, 2, 6}; // File sizes
    int n = sizeof(sizes) / sizeof(sizes[0]);

    int totalCost = optimalMergeCost(sizes, n);
    printf("Total cost of merging files: %d\n", totalCost);

    return 0;
}
//time complexity O(n)
