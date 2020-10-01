#include <bits/stdc++.h>
#define ll long long
#define omar main
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//push_back make_pair emplace vector double float _unordered_map unodered_set queue stack sort begin end clear second first
using namespace std;
int n, m;
const int N = 5 + 2e5;
int cycles = 0;
vector<vector<int>> graph(N);
bool visited[N], piv = 1;
void dfs(int idx){
	if (graph[idx].size() != 2) piv = 0;
	for (int i = 0 ; i < graph[idx].size(); i++){
		if (visited[graph[idx][i]]) continue;
		visited[graph[idx][i]] = 1;
		dfs(graph[idx][i]);
	}
}
int omar() { fastIO
	cin >> n >> m; // n : num of nodes, m : num of edges
	for (int i = 0 ; i < m ; i++){
		int u, v; 
		cin >> u >> v;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	for (int i = 1; i <= n ; i++){
		if (!visited[i] && graph[i].size() > 1){
			
			visited[i] = 1;
			dfs(i);
			if (piv)cycles++; else piv = 1;
		}
	} cout << endl << cycles << endl;
}
