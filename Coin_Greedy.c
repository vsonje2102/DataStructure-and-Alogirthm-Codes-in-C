#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    int count = 0;

    // Traverse through the coins array
    for (int i = 0; i < n; i++) {
        // Use the largest coin denomination possible
        if (coins[i] <= amount) {
            int numCoins = amount / coins[i]; // Number of coins of this denomination
            count += numCoins;               // Add to total coin count
            amount -= numCoins * coins[i];   // Reduce the remaining amount
        }
    }

    // If there is no amount left, print the result
    if (amount == 0) {
        printf("Minimum coins required: %d\n", count);
    } else {
        printf("Amount cannot be formed with the given coin denominations.\n");
    }
}

int main() {
    int coins[] = {25, 10, 5, 1};  // Example denominations (larger to smaller order)
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 63;                // Example amount to make

    coinChange(coins, n, amount);

    return 0;
}
//time complexity  O(n)
