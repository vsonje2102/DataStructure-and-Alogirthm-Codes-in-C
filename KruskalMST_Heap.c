#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    Edge edges[E];
    int size;
} MinHeap;

void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->edges[left].weight < heap->edges[smallest].weight)
        smallest = left;

    if (right < heap->size && heap->edges[right].weight < heap->edges[smallest].weight)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->edges[smallest], &heap->edges[idx]);
        minHeapify(heap, smallest);
    }
}

void insert(MinHeap* heap, Edge edge) {
    int idx = heap->size;
    heap->edges[idx] = edge;
    heap->size++;

    while (idx && heap->edges[(idx - 1) / 2].weight > heap->edges[idx].weight) {
        swap(&heap->edges[(idx - 1) / 2], &heap->edges[idx]);
        idx = (idx - 1) / 2;
    }
}

Edge extractMin(MinHeap* heap) {
    Edge root = heap->edges[0];
    heap->edges[0] = heap->edges[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(int graph[V][V]) {
    MinHeap heap = { .size = 0 };
    Edge edges[E];
    int k = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        insert(&heap, edges[i]);
    }

    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edge \tWeight\n");
    while (heap.size > 0) {
        Edge edge = extractMin(&heap);
        int u = edge.u;
        int v = edge.v;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y) {
            printf("%d - %d \t%d\n", u, v, edge.weight);
            unionSets(parent, rank, x, y);
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
