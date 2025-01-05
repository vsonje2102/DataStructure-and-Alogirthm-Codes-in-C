#include <stdio.h>
#include <string.h>

void printLCS(char *X, char *Y, int m, int n, int dp[m+1][n+1]) {
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Null-terminate the LCS string
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m+1][n+1];
    
    // Compute the LCS length using DP
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    printf("Length of LCS is %d\n", dp[m][n]);
    printLCS(X, Y, m, n, dp);
    return 0;
}

