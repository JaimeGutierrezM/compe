//inthepictures
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int64_t count_ways(int f, int N, int S) {
    if (N == 0) return S == 0 ? 1 : 0;
    
    if (S < N || S > N * f) return 0;
    
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(S + 1, 0));
    dp[0][0] = 1; 
    
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= min(S, i * f); ++j) {
            for (int k = 1; k <= min(f, j); ++k) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    
    return dp[N][S];
}

string probability_dice(int f, int N, int S) {
    int64_t favorable = count_ways(f, N, S);
    
    int64_t total = 1;
    for (int i = 0; i < N; ++i) {
        total *= f;
    }
    
    if (favorable == 0) return "0";
    
    return to_string(favorable) + "/" + to_string(total);
}

int main() {
    int f, N, S;
    while (cin >> f >> N >> S) {
        cout << probability_dice(f, N, S) << endl;
    }
    return 0;
}