#include<bits/stdc++.h>
using namespace std;
/*void DFS(int node,vector<int>&visited,vector<int>adjList[]){
	visited[node]=1;
	cout<<node<<" ";
	for(auto child:adjList[node]){
		if(visited[child]==0){
			DFS(child,visited,adjList);
		}
	}
}*/
void BFS(int node,vector<int>&visited,vector<int>adjList[]){
	queue<int>Q;
	Q.push(node);
	visited[node]=1;
	while(!Q.empty()){
		node=Q.front();
        Q.pop();
		cout<<node<<" ";
		for(auto i:adjList[node]){
			if(visited[i]==0){
				Q.push(i);
				visited[i]=1;
			}
		}
	}
}
int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int>adjList[nodes+1];
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
	    adjList[u].push_back(v);
	    adjList[v].push_back(u);
	}
	vector<int>visited(nodes+1,0);
	/*int total_components=0;
	for(int i=0;i<=nodes;i++){
		if(visited[i]==0){
			total_components++;
			DFS(i,visited,adjList);
		}
	}*/
	for(int i=1;i<=nodes;i++){
		if(!visited[i]){
			BFS(i,visited,adjList);
		}
	}
}
/* input
nodes-3,edges-2
nodes 1->2,2->3
*/
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