#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for (auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    // distance array
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // queue: {stops, node, cost}
    queue<tuple<int,int,int>> q;
    q.push({0, src, 0});

    while (!q.empty()) {
        auto [stops, node, cost] = q.front();
        q.pop();

        if (stops > k) continue;

        for (auto &it : adj[node]) {
            int next = it.first;
            int price = it.second;

            if (cost + price < dist[next]) {
                dist[next] = cost + price;
                q.push({stops + 1, next, dist[next]});
            }
        }
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}
    };
    int src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);
    return 0;
}