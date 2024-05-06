/*Represent a given graph using adjacency list representation to perform DFS traversal on graph.*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &ans){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(visited[it]!=1){
            dfs(adj, it, visited, ans);
        }
    }
}

int main(){
    int V, E;
    cout<<"enter no. of edges and vertices: ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"enter the edges: ";
    for(int i = 0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V,0);
    vector<int> ans;
    int node = 0;
    dfs(adj, node, visited, ans);
    cout<<"DFS traversal : ";
    for(auto i : ans){
        cout<<i<<" ";
    }
}