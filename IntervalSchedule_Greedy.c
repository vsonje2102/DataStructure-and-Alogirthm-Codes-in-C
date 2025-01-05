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

// Function to select the maximum number of non-overlapping intervals
void intervalScheduling(Interval intervals[], int n) {
    // Sort intervals by their finish times
    qsort(intervals, n, sizeof(Interval), compare);

    int count = 1;  // The first interval is always selected
    int lastSelected = 0;  // Index of the last selected interval

    printf("Selected intervals: \n");
    printf("Start: %d, End: %d\n", intervals[lastSelected].start, intervals[lastSelected].end);

    for (int i = 1; i < n; i++) {
        // If the current interval does not overlap with the last selected one
        if (intervals[i].start >= intervals[lastSelected].end) {
            lastSelected = i;  // Select the current interval
            count++;  // Increase the count of selected intervals
            printf("Start: %d, End: %d\n", intervals[lastSelected].start, intervals[lastSelected].end);
        }
    }

    printf("Total selected intervals: %d\n", count);
}

int main() {
    // Example intervals (start, end)
    Interval intervals[] = {{1, 3}, {2, 5}, {4, 7}, {6, 8}, {5, 9}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    intervalScheduling(intervals, n);

    return 0;
}
//time complexity O(n logn)
