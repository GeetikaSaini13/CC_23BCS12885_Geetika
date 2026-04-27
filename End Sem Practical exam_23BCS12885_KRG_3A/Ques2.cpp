#include <bits/stdc++.h>
using namespace std;

int tsp(int n, vector<vector<int>> &cost) {
int N = 1 << n;
vector<vector<int>> dp(N, vector<int>(n, INT_MAX));

dp[1][0] = 0; // start from city 0

for (int mask = 1; mask < N; mask++) {
for (int u = 0; u < n; u++) {
if (!(mask & (1 << u))) continue;

for (int v = 0; v < n; v++) {
if (mask & (1 << v) && v != u) {
int prev_mask = mask ^ (1 << u);
if (dp[prev_mask][v] != INT_MAX) {
dp[mask][u] = min(dp[mask][u],
dp[prev_mask][v] + cost[v][u]);
}}}}}

int ans = INT_MAX;
for (int i = 1; i < n; i++) {
if (dp[N - 1][i] != INT_MAX) {
ans = min(ans, dp[N - 1][i] + cost[i][0]);
 }
    }

 return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum TSP cost: " << tsp(n, cost) << endl;
    return 0;
}