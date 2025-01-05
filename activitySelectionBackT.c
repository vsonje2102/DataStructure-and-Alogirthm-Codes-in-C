#include <stdio.h>

void findMaxActivities(int start[], int finish[], int n, int index, int count, int* maxCount) {
    if (index == n) {
        if (count > *maxCount) {
            *maxCount = count;
        }
        return;
    }
    if (index == 0 || finish[index - 1] <= start[index]) {
        findMaxActivities(start, finish, n, index + 1, count + 1, maxCount);
    }
    findMaxActivities(start, finish, n, index + 1, count, maxCount);
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    int maxCount = 0;
    findMaxActivities(start, finish, n, 0, 0, &maxCount);
    printf("Maximum number of activities: %d\n", maxCount);
    return 0;
}

