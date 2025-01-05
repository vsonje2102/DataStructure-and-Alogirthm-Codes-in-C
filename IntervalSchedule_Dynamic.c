#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparison function to sort intervals based on finish time
int compare(const void* a, const void* b) {
    Interval* interval1 = (Interval*)a;
    Interval* interval2 = (Interval*)b;
    return interval1->end - interval2->end;
}

// Function to find the maximum number of non-overlapping intervals using DP
int intervalScheduling(Interval intervals[], int n) {
    // Sort intervals by their finish times
    qsort(intervals, n, sizeof(Interval), compare);

    // DP array to store the maximum number of non-overlapping intervals
    int dp[n];
    dp[0] = 1;  // The first interval is always selected

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        dp[i] = 1;  // Default case: we select the current interval

        // Check if the current interval does not overlap with any previous ones
        for (int j = i - 1; j >= 0; j--) {
            if (intervals[i].start >= intervals[j].end) {
                dp[i] = dp[j] + 1;
                break;  // No need to check further
            }
        }
    }

    // The answer is the maximum value in the dp array
    int maxIntervals = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > maxIntervals) {
            maxIntervals = dp[i];
        }
    }

    return maxIntervals;
}

int main() {
    // Example intervals (start, end)
    Interval intervals[] = {{1, 3}, {2, 5}, {4, 7}, {6, 8}, {5, 9}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int maxIntervals = intervalScheduling(intervals, n);
    printf("Maximum number of non-overlapping intervals: %d\n", maxIntervals);

    return 0;
}
//time complexity O(n^2)
