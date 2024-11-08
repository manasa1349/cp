#include<bits/stdc++.h>
using namespace std;

void BFS(int node, vector<int>& visited, vector<vector<int>>& adjMatrix, int nodes) {
    queue<int> Q;
    Q.push(node);
    visited[node] = 1;
    
    while(!Q.empty()) {
        node = Q.front();
        Q.pop();
        cout << node << " ";
        
        for(int i = 1; i <= nodes; i++) {
            if(adjMatrix[node][i] == 1 && visited[i] == 0) {
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void DFS(int node, vector<int>& visited, vector<vector<int>>& adjMatrix, int nodes) {
    // Mark the node as visited
    visited[node] = 1;
    cout << node << " ";
    
    // Visit all the unvisited neighbors
    for(int i = 1; i <= nodes; i++) {
        if(adjMatrix[node][i] == 1 && visited[i] == 0) {
            DFS(i, visited, adjMatrix, nodes);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // Adjacency Matrix initialization (nodes+1 to use 1-based indexing)
    vector<vector<int>> adjMatrix(nodes + 1, vector<int>(nodes + 1, 0));
    
    // Reading edges
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Since it's an undirected graph
    }

    vector<int> visited(nodes + 1, 0);
    
    // Perform DFS for each component (if the graph is disconnected)
    cout << "DFS Traversal: ";
    for(int i = 1; i <= nodes; i++) {
        if(!visited[i]) {
            DFS(i, visited, adjMatrix, nodes);
        }
    }
    cout << endl;

    // Reset visited for BFS
    fill(visited.begin(), visited.end(), 0);
    
    // Perform BFS for each component (if the graph is disconnected)
    cout << "BFS Traversal: ";
    for(int i = 1; i <= nodes; i++) {
        if(!visited[i]) {
            BFS(i, visited, adjMatrix, nodes);
        }
    }
    cout << endl;
}
/*
Enter the number of vertices: 4 
Enter the number of edges: 5 
Enter the edges (u v): 
1 2 
2 3 
3 4 
1 3 
2 4 
Enter the starting vertex for traversal: 2 
BFT: 2 4 3 1  
DFT: 2 3 1 4 */