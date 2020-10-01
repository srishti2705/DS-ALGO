#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000; // Max Node number

int dis[MAXN][MAXN];

int main(){
  // initially dis[a][b] = inf
  // dis[a][a] (distance between each node and itself) is 0
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      dis[i][j] = INT_MAX;
      if (i == j) dis[i][j] = 0;
    }
  }
  // fill each of dis[a][b] with distance between node a and b
  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int a, b, distance;
    cin >> a >> b >> distance;
    // distance between node a and node b is distance
    dis[a][b] = min(dis[a][b], distance);
    dis[b][a] = min(dis[b][a], distance);
  }

  for (int k = 0; k < MAXN; k++) {
    for (int i = 0; i < MAXN; i++) {
      for (int j = 0; j < MAXN; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
      }
    }
  }

  // dis[a][b] is the smallest distance between node a and b
  // if dis[a][b] is INT_MAX, node a are not reachable from node b, and node b are not reachable from node a
}