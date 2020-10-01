#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000; // Max Node number

struct EDGE {
  int u; 
  long long w;
  bool operator < (const EDGE & o) const {
    return w > o.w;
  }
};

vector <EDGE> g[MAXN];
priority_queue <EDGE> heap;
long long dis[MAXN];

bool visited[MAXN];

int main(){
  int e; cin >> e;
  for (int i = 0; i < e; i++) {
    // for each edge
    int a, b, distance;
    cin >> a >> b >> distance;
    // from node a to node b with distance = distance
    // note that edge is directed
    g[a].push_back({b, distance});
  }
  int startNode;
  cin >> startNode;
  heap.push({startNode, 0});
  while (!heap.empty()) {
    auto t = heap.top(); heap.pop();
    if (visited[t.u]) continue;
    visited[t.u] = 1;
    dis[t.u] = t.w;
    for (auto x : g[t.u]) {
      heap.push({x.u, t.w+x.w});
    }
  }

  // distance from startNode to any node x is equal to dis[x]
}