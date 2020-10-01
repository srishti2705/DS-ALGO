#include<bits/stdc++.h>
using namespace std;
#define iPair pair<int,int> 
#define INF INT_MAX

/* 
   Get the shortest from source node (src) to all other nodes.
	 Storing the distances from src in the distance vector.
*/

void Dijkestra(int src, vector<vector<iPair>> &adj, vector<int> &distance)
{
		priority_queue<iPair> q; // {weight, id}
		
    distance[src] = 0;
    q.push({0, src});

    while(!q.empty()) {

			int u = q.top().second;

			q.pop();
			
			for(iPair node : adj[u]){
				
				int v = node.first; // next node

				int weight = node.second; // between u and v

				if(distance[v] > distance[u] + weight)
				{
					distance[v] = distance[u] + weight;
					q.push({distance[v], v});
				}
			}
    }
}

int main()
{
	int nodes, edges;
	cout<<"Enter No of Nodes ";
	cin>>nodes;
	cout<<"Enter No of edges ";
	cin>>edges;
	vector<vector<iPair>> adj(nodes);

	for(int i=0;i<edges;i++)
	{
			int u, v, dis;
			cin>>u;
			cin>>v;
			cout << "Enter distance between " << u << " and " << v;
			cin >> dis;

			adj[u].push_back({v, dis});
			adj[v].push_back({u, dis});
	}
	vector<int> distance(nodes);

	for(int i=0; i<nodes;i++) {
		distance[i] = INF;
	}
	
	int source;
	cout << "Select the source node ";
	cin >> source;
	Dijkestra(source, adj ,distance);

	cout << "result: \n";

	for(int i=0; i< nodes;i++) {
		cout << "from " << source << " to " << i << " => " << distance[i] << '\n';
	}

	return 0;
}