#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void* a, const void* b) {
    float r1 = ((Item*)a)->ratio;
    float r2 = ((Item*)b)->ratio;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    return 0;
}

float fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n = 4;  // Number of items
    Item items[] = {
        {10, 60, 0}, // weight, value
        {20, 100, 0},
        {30, 120, 0},
        {40, 240, 0}
    };

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    int capacity = 50; // Knapsack capacity

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
//time complexity O(n log n)
