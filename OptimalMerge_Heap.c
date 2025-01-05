#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function to maintain the heap property
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Function to insert an element into the min-heap
void insertHeap(int heap[], int *n, int value) {
    heap[*n] = value;
    (*n)++;
    int i = (*n - 1) / 2;
    while (i >= 0) {
        minHeapify(heap, *n, i);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
int extractMin(int heap[], int *n) {
    if (*n <= 0)
        return -1;
    int min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return min;
}

// Function to calculate the total cost of merging the files optimally
int optimalMergeCost(int files[], int n) {
    int totalCost = 0;
    // Build the min-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(files, n, i);

    // Merge files until only one file remains
    while (n > 1) {
        int min1 = extractMin(files, &n); // Extract the smallest file
        int min2 = extractMin(files, &n); // Extract the next smallest file

        int mergeCost = min1 + min2; // The cost of merging these two files
        totalCost += mergeCost;

        // Insert the merged file back into the heap
        insertHeap(files, &n, mergeCost);
    }

    return totalCost;
}

int main() {
    int files[] = {4, 3, 2, 6}; // Example file sizes
    int n = sizeof(files) / sizeof(files[0]);

    int totalCost = optimalMergeCost(files, n);
    printf("Total cost of merging files: %d\n", totalCost);

    return 0;
}
//time complexity O(n log n)
