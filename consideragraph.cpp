//consideragraph
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DFS to mark all nodes in a connected component
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); // Consume newline after T
    cin.ignore(); // Consume blank line

    for (int t = 1; t <= T; ++t) {
        char max_node;
        cin >> max_node;
        cin.ignore(); // Consume newline

        // Initialize adjacency list for nodes 'A' to max_node
        int n = max_node - 'A' + 1;
        vector<vector<int>> adj(n);
        string line;
        while (getline(cin, line) && !line.empty()) {
            char u = line[0], v = line[1];
            int u_idx = u - 'A', v_idx = v - 'A';
            adj[u_idx].push_back(v_idx);
            adj[v_idx].push_back(u_idx); // Undirected graph
        }

        // Count connected components
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                ++components;
            }
        }

        // Output result
        cout << components << '\n';
        if (t < T) cout << '\n'; // Blank line between test cases
    }

    return 0;
}