//yesterdayyou
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

struct Edge {
    int u, v;
    ll ppa;
};

int dfs(int node, double threshold, const vector<vector<pair<int, ll>>>& adj, vector<bool>& visited) {
    visited[node] = true;
    int size = 1;
    for (const pair<int, ll>& edge : adj[node]) {
        int neighbor = edge.first;
        ll ppa = edge.second;
        if (!visited[neighbor] && ppa >= threshold) {
            size += dfs(neighbor, threshold, adj, visited);
        }
    }
    return size;
}

int max_component_size(int n, double threshold, const vector<vector<pair<int, ll>>>& adj) {
    vector<bool> visited(n, false);
    int max_size = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int size = dfs(i, threshold, adj, visited);
            max_size = max(max_size, size);
        }
    }
    return max_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        // Read edges
        vector<Edge> edges(m);
        vector<vector<pair<int, ll>>> adj(n);
        vector<ll> all_ppa;
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].ppa;
            --edges[i].u; --edges[i].v; // Convert to 0-based indexing
            adj[edges[i].u].push_back({ edges[i].v, edges[i].ppa });
            adj[edges[i].v].push_back({ edges[i].u, edges[i].ppa });
            all_ppa.push_back(edges[i].ppa);
        }

        sort(all_ppa.begin(), all_ppa.end());
        all_ppa.erase(unique(all_ppa.begin(), all_ppa.end()), all_ppa.end());
        int max_cities = 1;
        double left = all_ppa[0], right = all_ppa.back();
        for (int iter = 0; iter < 100; ++iter) {
            double mid = (left + right) / 2;
            int size = max_component_size(n, mid, adj);
            if (size > 1) { 
                max_cities = max(max_cities, size);
                left = mid;
            }
            else {
                right = mid;
            }
        }

        
        cout << max_cities << '\n';
    }

    return 0;
}