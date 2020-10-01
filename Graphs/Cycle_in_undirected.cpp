#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int node,vector<vector<int>> &adj,vector<bool> &visited, int parent)
{
    visited[node] = true;
    for(auto i = adj[node].begin(); i!=adj[node].end(); i++)
    {
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i,adj , visited, node)) 
              return true; 
        } 
  
        else if (*i != parent) 
           return true; 
    }
    return false;
}

bool isCyclic(int nodes, vector<vector<int>> &adj, vector<bool> &visited)
{
    for(int i=0;i<nodes;i++)
    {
        if(!visited[i])
            if(isCyclicUtil(i,adj, visited, -1))
                return true;
    }
    return false;
}

int main()
{
    int nodes,edges;
    cout<<"Enter No of Nodes: ";
    cin>>nodes;
    cout<<"Enter No of Edges: ";
    cin>>edges;
    vector<vector<int>> adj(nodes);
    for(int i=0; i<edges;i++)
    {
        int u,v;
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
    if(isCyclic(nodes,adj,visited))
        cout<<"Cyclic Graph";
    else
        cout<<"Uncyclic Graph";
}



// INTERVIEW BIT SOLUTION
// bool findCycle(int cur, vector<vector<int>>&adj, vector<bool>&visited, int parent)
// {
//     visited[cur] = true;
//     for(auto i=adj[cur].begin();i!=adj[cur].end();i++)
//     {
//         if(!visited[*i])
//         {
//             if(findCycle(*i,adj,visited,cur))
//                 return true;
//         }
//         else if(*i != parent)
//             return true;
//     }
    
//     return false;
// }

// int Solution::solve(int A, vector<vector<int> > &B) {
//     vector<vector<int>>adj(A+1);
//     for(int i = 0; i < B.size(); ++i){
//         adj[B[i][0]].push_back(B[i][1]);
//         adj[B[i][1]].push_back(B[i][0]);
//     }
//     vector<bool>visited(A+1);
    
//     for(int v=1;v<=A;++v)
//     {
//         if(!visited[v])
//         {
//             if(findCycle(v, adj, visited, 0)){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }
