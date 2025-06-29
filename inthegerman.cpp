//inthegerman
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_combinations(const vector<int>& S, int k, int pos, int count, vector<int>& current, vector<vector<int>>& results) {
    if (count == 6) {
        results.push_back(current);
        return;
    }
    if (pos >= k || k - pos < 6 - count) return; // Not enough numbers left
    // Include S[pos]
    current.push_back(S[pos]);
    generate_combinations(S, k, pos + 1, count + 1, current, results);
    current.pop_back();
    // Exclude S[pos]
    generate_combinations(S, k, pos + 1, count, current, results);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool first_case = true;
    while (true) {
        int k;
        cin >> k;
        if (k == 0) break;

        // Read the set S
        vector<int> S(k);
        for (int i = 0; i < k; ++i) {
            cin >> S[i];
        }

        // Generate all combinations
        vector<vector<int>> results;
        vector<int> current;
        generate_combinations(S, k, 0, 0, current, results);

        // Sort results lexicographically (already sorted due to input and generation order)
        // Print results
        if (!first_case) cout << '\n'; // Blank line between test cases
        first_case = false;
        for (const auto& combo : results) {
            for (int i = 0; i < 6; ++i) {
                cout << combo[i];
                if (i < 5) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}