#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void bfsList(Node* adjList[], int start, int V) {
    int visited[V];
    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* temp = adjList[vertex];
        while (temp) {
            int connectedVertex = temp->vertex;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                queue[rear++] = connectedVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V = 5;
    Node* adjList[V];

    for (int i = 0; i < V; i++) adjList[i] = NULL;

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);

    printf("BFS (Adjacency List): ");
    bfsList(adjList, 0, V);
    printf("\n");
    return 0;
}

