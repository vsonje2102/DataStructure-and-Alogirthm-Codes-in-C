#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define INF INT_MAX

typedef struct {
    int vertex;
    int key;
} PriorityQueue;

PriorityQueue pq[V];
int pqSize = 0;

void swap(PriorityQueue *a, PriorityQueue *b) {
    PriorityQueue temp = *a;
    *a = *b;
    *b = temp;
}

void insertPQ(int vertex, int key) {
    pq[pqSize].vertex = vertex;
    pq[pqSize].key = key;
    pqSize++;
}

int extractMin() {
    int minIndex = 0;
    for (int i = 1; i < pqSize; i++) {
        if (pq[i].key < pq[minIndex].key) {
            minIndex = i;
        }
    }
    int minVertex = pq[minIndex].vertex;
    pq[minIndex] = pq[pqSize - 1];
    pqSize--;
    return minVertex;
}

void decreaseKey(int vertex, int key) {
    for (int i = 0; i < pqSize; i++) {
        if (pq[i].vertex == vertex) {
            pq[i].key = key;
            break;
        }
    }
}

bool isInPQ(int vertex) {
    for (int i = 0; i < pqSize; i++) {
        if (pq[i].vertex == vertex)
            return true;
    }
    return false;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int key[V];
    int parent[V];
    bool inMST[V];
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
        insertPQ(i, key[i]);
    }
    key[0] = 0;
    decreaseKey(0, key[0]);
    while (pqSize > 0) {
        int u = extractMin();
        inMST[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                decreaseKey(v, key[v]);
            }
        }
    }
    printMST(parent, graph);
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

//Time Complexity O(V^2)
