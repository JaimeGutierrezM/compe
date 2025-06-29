//forhundreds
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Store results as vector of {a, b, c, d}
    vector<vector<ll>> results;

    // Precompute cubes up to 200^3
    const ll MAX_A = 200;
    ll max_cube = MAX_A * MAX_A * MAX_A;
    for (ll b = 2; b <= MAX_A; ++b) {
        ll b3 = b * b * b;
        for (ll c = b; c <= MAX_A; ++c) {
            ll c3 = c * c * c;
            for (ll d = c; d <= MAX_A; ++d) {
                ll d3 = d * d * d;
                ll sum = b3 + c3 + d3;
                if (sum > max_cube) break; // Sum exceeds 200^3
                ll a = round(cbrt(sum)); // Approximate cube root
                if (a > MAX_A || a < 2) continue; // a must be <= 200 and > 1
                if (a * a * a == sum) { // Check if perfect cube
                    results.push_back({ a, b, c, d });
                }
            }
        }
    }

    // Sort results by a, then b, then c, then d
    sort(results.begin(), results.end(), [](const vector<ll>& x, const vector<ll>& y) {
        if (x[0] != y[0]) return x[0] < y[0];
        if (x[1] != y[1]) return x[1] < y[1];
        if (x[2] != y[2]) return x[2] < y[2];
        return x[3] < y[3];
        });

    // Output results
    for (const auto& r : results) {
        cout << "Cube = " << r[0] << ", Triple = (" << r[1] << "," << r[2] << "," << r[3] << ")\n";
    }

    return 0;
}