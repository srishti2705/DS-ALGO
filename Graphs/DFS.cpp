#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    cout<<u<<" ";
    for(int v: adj[u])
    {
        if(!visited[v])
            dfs(v, adj, visited);
    }
}


int main()
{
    int nodes, edges, u, v;
    cout<<"Enter No of Nodes:";
    cin >> nodes;
    cout<<"Enter No of Edges:";
    cin>>edges;
    vector<vector<int>> adj(nodes);
    vector<bool> visited(nodes);
    for(int i = 1; i<=edges; i++)
    {
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i<nodes; i++)
        visited[i] = false;
    dfs(2, adj, visited);
}