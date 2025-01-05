#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void* a, const void* b) {
    return ((Item*)b)->ratio - ((Item*)a)->ratio;
}

float fractionalKnapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
    
    int currentWeight = 0;
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Knapsack capacity
    Item items[] = {
        {10, 60, 0.0},
        {20, 100, 0.0},
        {30, 120, 0.0}
    };
    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Maximum value we can obtain: %.2f\n", fractionalKnapsack(W, items, n));
    return 0;
}
//time complexity O(n log n)
