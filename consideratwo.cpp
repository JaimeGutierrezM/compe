//consideratwo
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dfs(vector<vector<char>>& grid, int rows, int cols, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0' || visited[r][c]) return 0;
    visited[r][c] = true;
    int size = 1;

    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < 8; ++i) {
        size += dfs(grid, rows, cols, r + dr[i], c + dc[i], visited);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); 
    cin.ignore(); 

    for (int t = 1; t <= T; ++t) {
        
        vector<vector<char>> grid;
        string line;
        while (getline(cin, line) && !line.empty()) {
            vector<char> row(line.begin(), line.end());
            grid.push_back(row);
        }

        int rows = grid.size();
        int cols = rows > 0 ? grid[0].size() : 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int max_blob_size = 0;

       
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    int blob_size = dfs(grid, rows, cols, i, j, visited);
                    max_blob_size = max(max_blob_size, blob_size);
                }
            }
        }

        
        cout << max_blob_size << '\n';
        if (t < T) cout << '\n';
    }

    return 0;
}