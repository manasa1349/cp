#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

void DFS(int node, int visited[], int adjMatrix[MAX_NODES][MAX_NODES], int nodes) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 1; i <= nodes; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            DFS(i, visited, adjMatrix, nodes);
        }
    }
}

void BFS(int startNode, int visited[], int adjMatrix[MAX_NODES][MAX_NODES], int nodes) {
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = startNode;
    visited[startNode] = 1;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 1; i <= nodes; i++) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int nodes, edges, start;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    int adjMatrix[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix initialization
    int visited[MAX_NODES] = {0};             // Visited array for traversal

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    printf("Enter the starting node for traversal: ");
    scanf("%d", &start);

    printf("DFS Traversal:\n");
    DFS(start, visited, adjMatrix, nodes);

    // printf("DFS Traversal:\n");
    // for (int i = 1; i <= nodes; i++) {
    //     if (!visited[i]) {
    //         DFS(i, visited, adjMatrix, nodes);
    //     }
    // }

    // Reset visited array for BFS
    for (int i = 0; i <= nodes; i++) {
        visited[i] = 0;
    }


    // printf("\nBFS Traversal:\n");
    // for (int i = 1; i <= nodes; i++) {
    //     if (!visited[i]) {
    //         BFS(i, visited, adjMatrix, nodes);
    //     }
    // }


    printf("\nBFS Traversal:\n");
    BFS(start, visited, adjMatrix, nodes);

    return 0;
}