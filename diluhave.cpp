//diluhave
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute primes and count of primes <= i
    vector<bool> is_prime(MAX_N + 1, true);
    vector<int> prime_count(MAX_N + 1, 0);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
        prime_count[i] = prime_count[i - 1] + (is_prime[i] ? 1 : 0);
    }

    // Compute divisors for each number
    vector<vector<int>> divisors(MAX_N + 1);
    for (int p : primes) {
        for (int j = p; j <= MAX_N; j += p) {
            divisors[j].push_back(p);
        }
    }

    // Compute expected moves
    vector<double> dp(MAX_N + 1, 0.0);
    for (int n = 2; n <= MAX_N; ++n) {
        if (divisors[n].empty()) { // Prime number
            dp[n] = 1.0 + dp[n]; // E[n] = 1 + E[n] (will be handled by division by zero avoidance)
        }
        else {
            double sum = 0.0;
            for (int p : divisors[n]) {
                sum += dp[n / p];
            }
            int div_count = divisors[n].size();
            dp[n] = (sum + prime_count[n]) / div_count;
        }
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cout << "Case " << t << ": ";
        cout.setf(ios::fixed);
        cout.precision(10);
        cout << dp[N] << '\n';
    }

    return 0;
}