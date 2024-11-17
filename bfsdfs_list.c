#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdge(Graph* graph, int src, int dest);
void DFS(Graph* graph, int vertex, int* visited);
void BFS(Graph* graph, int startVertex, int* visited);

int main() {
    int nodes, edges, start;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    Graph* graph = createGraph(nodes);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter the starting node for traversal: ");
    scanf("%d", &start);

    int visited[MAX_NODES] = {0}; // Visited array for traversal

    printf("DFS Traversal:\n");
    DFS(graph, start, visited);

    // Reset visited array for BFS
    for (int i = 0; i <= nodes; i++) {
        visited[i] = 0;
    }

    printf("\nBFS Traversal:\n");
    BFS(graph, start, visited);

    return 0;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc((vertices + 1) * sizeof(Node*));

    for (int i = 0; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS implementation
void DFS(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// BFS implementation
void BFS(Graph* graph, int startVertex, int* visited) {
    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
