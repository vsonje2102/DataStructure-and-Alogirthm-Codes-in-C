#include <stdio.h>
#include <stdlib.h>
// Function to compute Fibonacci using memoization
int fibo(int n, int *new_array) {
    if (n <= 1) {
        return n; // Base case
    }
    if (new_array[n] != -1) { // If already computed
        return new_array[n];
    }
    // Recursive computation
    int x = fibo(n - 1, new_array);
    int y = fibo(n - 2, new_array);
    new_array[n] = x + y; // Store result in memoization table
    return new_array[n];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid Arguments\nUsage: %s <fib n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        printf("Please provide a non-negative integer.\n");
        return 1;
    }

    // Allocate memory for memoization
    int *new_array = (int *)malloc((n + 1) * sizeof(int));
    if (new_array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array with -1
    for (int i = 0; i <= n; i++) {
        new_array[i] = -1;
    }

    // Compute the nth Fibonacci number
    int result = fibo(n, new_array);
    printf("The %dth Fibonacci number is %d\n", n, result);

    // Free the allocated memory
    free(new_array);

    return 0;
}

