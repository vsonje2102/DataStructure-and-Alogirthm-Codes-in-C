#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

typedef struct {
    Edge heap[E];
    int size;
} MinHeap;

void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left].weight < minHeap->heap[smallest].weight)
        smallest = left;

    if (right < minHeap->size && minHeap->heap[right].weight < minHeap->heap[smallest].weight)
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->heap[smallest], &minHeap->heap[idx]);
        minHeapify(minHeap, smallest);
    }
}

Edge extractMin(MinHeap* minHeap) {
    Edge root = minHeap->heap[0];
    minHeap->heap[0] = minHeap->heap[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(MinHeap* minHeap, int vertex, int weight) {
    int i = vertex;
    minHeap->heap[i].weight = weight;

    while (i && minHeap->heap[i].weight < minHeap->heap[(i - 1) / 2].weight) {
        swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(int graph[V][V]) {
    MinHeap minHeap = {.size = 0};
    Edge edges[E];
    int k = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].weight = graph[i][j];
                minHeap.heap[minHeap.size++] = edges[k];
                k++;
            }
        }
    }

    for (int i = (minHeap.size / 2) - 1; i >= 0; i--)
        minHeapify(&minHeap, i);

    Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Edge \tWeight\n");
    while (minHeap.size > 0) {
        Edge edge = extractMin(&minHeap);
        int u = edge.u;
        int v = edge.v;

        int x = find(subsets, u);
        int y = find(subsets, v);

        if (x != y) {
            printf("%d - %d \t%d\n", u, v, edge.weight);
            unionSets(subsets, x, y);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 5, 0},
        {3, 0, 4, 7, 6},
        {0, 4, 0, 0, 8},
        {5, 7, 0, 0, 2},
        {0, 6, 8, 2, 0}
    };

    kruskalMST(graph);
    return 0;
}
//time complexity O(E log E)
