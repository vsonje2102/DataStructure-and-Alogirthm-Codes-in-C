#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jobId;
    int profit;
    int deadline;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        schedule[i] = -1;

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].jobId;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled jobs: \n");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            for (int j = 0; j < n; j++) {
                if (jobs[j].jobId == schedule[i]) {
                    printf("Job ID: %d, Profit: %d\n", jobs[j].jobId, jobs[j].profit);
                    break;
                }
            }
        }
    }
    printf("Total profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {
        {1, 20, 2},
        {2, 10, 2},
        {3, 10, 1},
        {4, 5, 3},
        {5, 1, 3}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

    return 0;
}


