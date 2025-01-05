#include <stdio.h>
#include <string.h>

int lcsRecursive(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (X[m - 1] == Y[n - 1]) {
        return 1 + lcsRecursive(X, Y, m - 1, n - 1);
    } else {
        return (lcsRecursive(X, Y, m - 1, n) > lcsRecursive(X, Y, m, n - 1)) ?
               lcsRecursive(X, Y, m - 1, n) : lcsRecursive(X, Y, m, n - 1);
    }
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d\n", lcsRecursive(X, Y, m, n));
    return 0;
}

