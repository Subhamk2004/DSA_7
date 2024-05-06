#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V, int node)
{
    vector<int> visited(V, 0);
    vector<int> ans;
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();

        for (auto i : adj[curr])
        {
            if (visited[i] != 1)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int node = 0;
    vector<int> ans = bfs(adj, V, node);
    cout << "BFS traversal : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
