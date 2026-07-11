#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--; f--;
    
    vector<vector<Edge>> g(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    
    const int INF = 1e9;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d != dist[u]) continue;
        if (u == f) break;
        
        for (const auto& e : g[u]) {
            if (dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    
    cout << dist[f] << '\n';
    
    return 0;
}
