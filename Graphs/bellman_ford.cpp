// g++ bellman_ford.cpp -o bellman_ford && ./bellman_ford

/*


*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define endl '\n'
#define ll long long int
using namespace std;
#define pii pair <ll , ll >
#define vin vector<int>
#define vll vector<long long>
#define deb(x) cout << #x << " " << x << endl
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl
#define loop(n) for(int i = 0; i < n; i++)
#define pb push_back
vector<vin>  ad_mat(9, vin(9, INT_MAX));
vector<vin> edge_weight;

int main(){

    // putting weights of edges
    ad_mat[1][2] = 2;
    ad_mat[2][3] = 4;
    ad_mat[3][8] = 1;
    ad_mat[3][4] = 3;
    ad_mat[1][4] = 3;
    ad_mat[4][5] = 3;
    ad_mat[4][7] = 2;
    ad_mat[5][6] =4 ;
    ad_mat[6][7] = 5;
    ad_mat[7][8] = 2;


    // now making list of edges and virteces
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (ad_mat[i][j] < INT_MAX) {
                vin temp(3);
                temp[0] = i;
                temp[1] = j;
                temp[2] = ad_mat[i][j];
                edge_weight.pb(temp);
            }
        }
    }
    int virtex_count = 8, source;
    vin dis(9, INT_MAX-10000);
    cout << "Enter source " << endl;
    cin >> source;
    dis[source] = 0;
    loop(10){
        for(auto ed: edge_weight){
            if(dis[ed[0]] < dis[ed[0]] + ad_mat[ed[0]][ed[1]]) dis[ed[0]] = dis[ed[0]] + ad_mat[ed[0]][ed[1]];
        }
    }
    bool flag = false;
    for(auto ed: edge_weight) if(dis[ed[0]] < dis[ed[0]] + ad_mat[ed[0]][ed[1]]) flag = true;
    if (flag) cout << "negative edge cycle detected" << endl;
    else for(int i = 1; i < 9; i++) cout << dis[i] << " "; cout << endl;
    
}