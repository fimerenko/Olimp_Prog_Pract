#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[k] = 0;
    q.push(k);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dist[i] << (i == n - 1 ? '\n' : ' ');
    }
    
    return 0;
}
