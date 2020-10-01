#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &adj,int u,int v)
{
    adj[u].push_back(v);
}

void util(int v,vector<vector<int>> &adj, vector<bool> &visited,stack<int> &s)
{
    visited[v] = true;
    
    for(auto i = adj[v].begin();i!=adj[v].end();i++)
        if(!visited[*i])
            util(*i,adj,visited,s);
            
    
    s.push(v);
}

void topologicalSort(vector<vector<int>> &adj,int nodes)
{
    vector<bool> visited(nodes,false);
    stack<int> s;
    for(int i=0;i<nodes;i++)
    {
        if(visited[i] == false)
        {
            util(i,adj,visited,s);
        }
    }

    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    vector<vector<int>> adj(6);
    addEdge(adj,5, 2); 
    addEdge(adj,5, 0); 
    addEdge(adj,4, 0); 
    addEdge(adj,4, 1); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1); 
    topologicalSort(adj,6);
    return 0;
}