//arobot
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Structure to track position
struct Pos {
    int row, col;
    bool operator<(const Pos& other) const {
        return row == other.row ? col < other.col : row < other.row;
    }
};

int main() {
    while (true) {
        int R, C, S;
        cin >> R >> C >> S;
        if (R == 0 && C == 0 && S == 0) break;

        // Read grid
        vector<string> grid(R);
        for (int i = 0; i < R; ++i) {
            cin >> grid[i];
        }

        // Track visited positions and step counts
        map<Pos, int> visited;
        Pos current = {0, S - 1}; // Start at row 0, column S-1 (0-based)
        int steps = 0;
        bool exited = false;

        while (true) {
            // Check if out of grid
            if (current.row < 0 || current.row >= R || current.col < 0 || current.col >= C) {
                cout << steps << " step(s) to exit" << endl;
                exited = true;
                break;
            }

            // Check if position was visited
            if (visited.count(current)) {
                int loop_start = visited[current];
                int loop_size = steps - loop_start;
                cout << loop_start << " step(s) before a loop of " << loop_size << " step(s)" << endl;
                break;
            }

            // Mark current position
            visited[current] = steps;

            // Follow instruction
            char instr = grid[current.row][current.col];
            if (instr == 'N') current.row--;
            else if (instr == 'S') current.row++;
            else if (instr == 'E') current.col++;
            else if (instr == 'W') current.col--;
            
            steps++;
        }
    }
    return 0;
}