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

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((float)W / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n = 4; // Number of items
    int W = 50; // Maximum weight capacity of knapsack

    Item items[] = {
        {10, 60, 0}, // {weight, value}
        {20, 100, 0},
        {30, 120, 0},
        {40, 240, 0}
    };

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
//time complexity O(n log n)
