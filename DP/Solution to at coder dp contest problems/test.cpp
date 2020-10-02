#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18L + 5;

vector<ll> pre; // preprocessing
// pre[mask] - score of group 'mask'
vector<ll> dp;

void rec(int i, const vector<int>& not_taken, ll score_so_far, int mask, int group) {
    if(i == (int) not_taken.size()) {
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }
    rec(i + 1, not_taken, score_so_far, mask, group);
    rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}

// O(2^n * n^2 + 3^n)

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<ll>> in(n, vector<ll>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lld", &in[i][j]);
        }
    }
    pre.resize(1 << n);
    // O(2^n * n^2)
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                for(int j = i + 1; j < n; ++j) {
                    if(mask & (1 << j)) {
                        pre[mask] += in[i][j];
                    }
                }
            }
        }
    }
    // dp[mask] - best total score if we grouped rabbits from 'mask' already
    dp.resize(1 << n, -INF);
    dp[0] = 0;
    // O(2^n * n + 3^n)
    for(int mask = 0; mask < (1 << n); ++mask) {
        vector<int> not_taken;
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) {
                not_taken.push_back(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }
    printf("%lld\n", dp[(1<<n)-1]);
}