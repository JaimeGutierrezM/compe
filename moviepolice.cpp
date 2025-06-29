//moviepolice
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// Compute Hamming distance between two strings of equal length
int hamming_distance(const string& s1, const string& s2) {
    int dist = 0;
    for (size_t i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) ++dist;
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, Q;
    cin >> M >> Q;

    // Read movie signatures
    vector<string> movies(M);
    for (int i = 0; i < M; ++i) {
        cin >> movies[i];
    }

    // Process each clip
    for (int q = 0; q < Q; ++q) {
        string clip;
        cin >> clip;
        int clip_len = clip.size();
        int min_dist = INT_MAX;
        int best_movie = 0;

        // Check each movie
        for (int i = 0; i < M; ++i) {
            if (movies[i].size() < clip_len) continue; // Skip if movie is too short
            // Slide clip over movie to find minimum Hamming distance
            for (int j = 0; j <= movies[i].size() - clip_len; ++j) {
                string substr = movies[i].substr(j, clip_len);
                int dist = hamming_distance(clip, substr);
                if (dist < min_dist || (dist == min_dist && i + 1 < best_movie)) {
                    min_dist = dist;
                    best_movie = i + 1; // 1-based index
                }
            }
        }

        cout << best_movie << '\n';
    }

    return 0;
}