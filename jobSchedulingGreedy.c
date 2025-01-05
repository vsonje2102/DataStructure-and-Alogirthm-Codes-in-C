#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Task;

int findAvailableSlot(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findAvailableSlot(parent, parent[i]);  // Path compression
}

void unionSlots(int parent[], int u, int v) {
    parent[u] = v;
}

int compare(const void* a, const void* b) {
    Task* t1 = (Task*)a;
    Task* t2 = (Task*)b;
    return t2->profit - t1->profit;  // Descending order of profit
}

void jobScheduling(Task tasks[], int n) {
    qsort(tasks, n, sizeof(Task), compare);  // Sort by profit

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (tasks[i].deadline > maxDeadline) maxDeadline = tasks[i].deadline;

    int* parent = (int*)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        int availableSlot = findAvailableSlot(parent, tasks[i].deadline);
        if (availableSlot > 0) {
            totalProfit += tasks[i].profit;
            unionSlots(parent, availableSlot, availableSlot - 1);
            printf("Task ID: %d (Profit: %d) scheduled at slot %d\n", tasks[i].id, tasks[i].profit, availableSlot);
        }
    }

    printf("Total Profit: %d\n", totalProfit);
    free(parent);
}

int main() {
    Task tasks[] = {{1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}};
    int n = sizeof(tasks) / sizeof(tasks[0]);

    jobScheduling(tasks, n);
    return 0;
}

