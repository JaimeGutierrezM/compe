//theinhabitants
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DFS to mark a connected component of 1's
void dfs(vector<vector<char>>& grid, int n, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '0' || visited[r][c]) return;
    visited[r][c] = true;
    // Check all 8 directions
    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 8; ++i) {
        dfs(grid, n, r + dr[i], c + dc[i], visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int image_num = 0;
    int n;
    while (cin >> n) {
        ++image_num;
        // Read the grid
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < n; ++j) {
                grid[i][j] = line[j];
            }
        }

        // Count connected components of 1's
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int war_eagles = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, n, i, j, visited);
                    ++war_eagles;
                }
            }
        }

        // Output result
        cout << "Image number " << image_num << " contains " << war_eagles << " war eagles.\n";
    }

    return 0;
}