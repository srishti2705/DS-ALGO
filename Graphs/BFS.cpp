#include<bits/stdc++.h>
using namespace std;

void BFS(int x, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int s = q.front();
        cout<<s<<" ";
        q.pop();
        for( int it = 0; it<adj[s].size();it++)
        {
            if(!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout<<"Enter No of Nodes";
    cin>>nodes;
    cout<<"Enter No of edges";
    cin>>edges;
    vector<vector<int>> adj(nodes);
    for(int i=0;i<edges;i++)
    {
        int u, v;
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(nodes);
    for(int i=0; i<nodes;i++)
    {
        visited[i] = false;
    }
    BFS(2, adj,visited);
}