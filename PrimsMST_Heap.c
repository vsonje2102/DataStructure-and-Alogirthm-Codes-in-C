#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define INF INT_MAX

typedef struct {
    int vertex, weight;
} HeapNode;

typedef struct {
    HeapNode heap[V];
    int size;
} MinHeap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx, int pos[]) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heap[left].weight < minHeap->heap[smallest].weight)
        smallest = left;

    if (right < minHeap->size && minHeap->heap[right].weight < minHeap->heap[smallest].weight)
        smallest = right;

    if (smallest != idx) {
        pos[minHeap->heap[smallest].vertex] = idx;
        pos[minHeap->heap[idx].vertex] = smallest;
        swap(&minHeap->heap[smallest], &minHeap->heap[idx]);
        minHeapify(minHeap, smallest, pos);
    }
}

HeapNode extractMin(MinHeap* minHeap, int pos[]) {
    HeapNode root = minHeap->heap[0];
    HeapNode lastNode = minHeap->heap[minHeap->size - 1];
    minHeap->heap[0] = lastNode;
    pos[lastNode.vertex] = 0;
    minHeap->size--;
    minHeapify(minHeap, 0, pos);
    return root;
}

void decreaseKey(MinHeap* minHeap, int vertex, int weight, int pos[]) {
    int i = pos[vertex];
    minHeap->heap[i].weight = weight;

    while (i && minHeap->heap[i].weight < minHeap->heap[(i - 1) / 2].weight) {
        pos[minHeap->heap[i].vertex] = (i - 1) / 2;
        pos[minHeap->heap[(i - 1) / 2].vertex] = i;
        swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(int vertex, int pos[], int size) {
    return pos[vertex] < size;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int pos[V];
    MinHeap minHeap = {.size = V};

    for (int v = 0; v < V; v++) {
        key[v] = INF;
        minHeap.heap[v] = (HeapNode){v, key[v]};
        pos[v] = v;
    }

    key[0] = 0;
    parent[0] = -1;
    decreaseKey(&minHeap, 0, 0, pos);

    while (minHeap.size > 0) {
        HeapNode minNode = extractMin(&minHeap, pos);
        int u = minNode.vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(v, pos, minHeap.size) && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                decreaseKey(&minHeap, v, key[v], pos);
            }
        }
    }

    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
    return 0;
}
//Time Complexity O(V^2) approx equal to no of edges
