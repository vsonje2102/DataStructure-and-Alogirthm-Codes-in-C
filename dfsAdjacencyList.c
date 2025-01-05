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

void dfsList(Node* adjList[], int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = adjList[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            dfsList(adjList, visited, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V = 5;
    Node* adjList[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);

    printf("DFS (Adjacency List): ");
    dfsList(adjList, visited, 0);
    printf("\n");
    return 0;
}

