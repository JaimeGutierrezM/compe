//onceupon
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C, M, N;
        cin >> R >> C >> M >> N;
        int W;
        cin >> W;

        // Mark water cells
        vector<vector<bool>> water(R, vector<bool>(C, false));
        for (int i = 0; i < W; ++i) {
            int x, y;
            cin >> x >> y;
            water[x][y] = true;
        }

        // BFS to find reachable squares from (0,0)
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<pii> q;
        q.push({ 0, 0 });
        visited[0][0] = true;
        vector<pii> reachable = { {0, 0} };

        // Possible move offsets
        vector<pii> moves;
        if (M == 0 && N == 0) {
            // No moves possible
        }
        else {
            moves = { {M, N}, {M, -N}, {-M, N}, {-M, -N}, {N, M}, {N, -M}, {-N, M}, {-N, -M} };
            // Remove duplicates if M == N or M == 0 or N == 0
            set<pii> unique_moves(moves.begin(), moves.end());
            moves.assign(unique_moves.begin(), unique_moves.end());
        }

        // BFS
        while (!q.empty()) {
            pii front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();
            for (const pii& move : moves) {
                int dr = move.first;
                int dc = move.second;
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && !water[nr][nc] && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({ nr, nc });
                    reachable.push_back({ nr, nc });
                }
            }
        }

        // Count in-degree for each reachable square
        vector<vector<int>> in_degree(R, vector<int>(C, 0));
        for (const pii& pos : reachable) {
            int r = pos.first;
            int c = pos.second;
            for (const pii& move : moves) {
                int dr = move.first;
                int dc = move.second;
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && !water[nr][nc] && visited[nr][nc]) {
                    in_degree[nr][nc]++;
                }
            }
        }

        // Count even and odd squares
        int even_count = 0, odd_count = 0;
        for (const pii& pos : reachable) {
            int r = pos.first;
            int c = pos.second;
            if (in_degree[r][c] % 2 == 0) {
                even_count++;
            }
            else {
                odd_count++;
            }
        }

        // Output result
        cout << "Case " << t << ": " << even_count << " " << odd_count << '\n';
    }

    return 0;
}