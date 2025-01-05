#include <stdio.h>
#include <limits.h>

void coinChange(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize dp array with a value larger than any possible number of coins
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Update dp array for each coin
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j] > dp[j - coins[i]] + 1) {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
    }

    if (dp[amount] != INT_MAX) {
        printf("Minimum coins required: %d\n", dp[amount]);
    } else {
        printf("Amount cannot be formed with the given coin denominations.\n");
    }
}

int main() {
    int coins[] = {25, 10, 5, 1}; // Example denominations
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 63; // Example amount to make

    coinChange(coins, n, amount);

    return 0;
}
//time complexity O(n * amount)
