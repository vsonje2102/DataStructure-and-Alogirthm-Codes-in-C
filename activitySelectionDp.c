#include <stdio.h>
#define MAX 100

int activitySelectionDP(int start[], int finish[], int n) {
    int dp[MAX][MAX] = {0};
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++) {
                if (finish[i] <= start[k] && finish[k] <= start[j]) {
                    dp[i][j] = (dp[i][j] > dp[i][k] + dp[k][j] + 1) ? dp[i][j] : dp[i][k] + dp[k][j] + 1;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int start[] = {0, 1, 3, 0, 5, 8, 5};
    int finish[] = {0, 2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    int result = activitySelectionDP(start, finish, n);
    printf("Maximum number of activities: %d\n", result);
    return 0;
}

