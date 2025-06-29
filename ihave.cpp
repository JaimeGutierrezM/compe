//ihave
#include <iostream>
#include <climits>

using namespace std;

using ll = long long;

// Compute GCD using Euclidean algorithm
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        ll n;
        cin >> n;
        if (n == 0) break; // Terminate on n = 0

        ll c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        // Check if n is divisible by GCD(n1, n2)
        ll g = gcd(n1, n2);
        if (n % g != 0) {
            cout << "failed\n";
            continue;
        }

        // Scale down to simplify calculations
        n /= g;
        n1 /= g;
        n2 /= g;

        // Find non-negative integer solutions: m1 * n1 + m2 * n2 = n
        // Try m1 from 0 to n/n1
        ll min_cost = LLONG_MAX;
        ll best_m1 = -1, best_m2 = -1;

        // m1 * n1 + m2 * n2 = n => m2 = (n - m1 * n1) / n2
        for (ll m1 = 0; m1 * n1 <= n; ++m1) {
            ll rem = n - m1 * n1;
            if (rem % n2 == 0) {
                ll m2 = rem / n2;
                ll cost = m1 * c1 + m2 * c2;
                if (cost < min_cost) {
                    min_cost = cost;
                    best_m1 = m1;
                    best_m2 = m2;
                }
            }
        }

        if (best_m1 == -1) {
            cout << "failed\n";
        }
        else {
            cout << best_m1 << ' ' << best_m2 << '\n';
        }
    }

    return 0;
}