#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex, weight;
} Node;

typedef struct {
    Node* array;
    int size, capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node*)malloc(capacity * sizeof(Node));
    return heap;
}

void swapNodes(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < heap->size && heap->array[left].weight < heap->array[smallest].weight)
        smallest = left;
    if (right < heap->size && heap->array[right].weight < heap->array[smallest].weight)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

Node extractMin(MinHeap* heap) {
    Node min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return min;
}

void insertMinHeap(MinHeap* heap, Node node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node.weight < heap->array[(i - 1) / 2].weight) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void dijkstra(int graph[5][5], int src, int V) {
    int dist[V], visited[V] = {0};
    MinHeap* heap = createMinHeap(V);
    
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    insertMinHeap(heap, (Node){src, 0});

    while (heap->size > 0) {
        Node current = extractMin(heap);
        int u = current.vertex;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                insertMinHeap(heap, (Node){v, dist[v]});
            }
        }
    }

    for (int i = 0; i < V; i++) printf("Vertex %d -> Distance from Source %d\n", i, dist[i]);
}

int main() {
    int graph[5][5] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };
    dijkstra(graph, 0, 5);
    return 0;
}

