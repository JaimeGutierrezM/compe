//ifyou
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

using ll = unsigned long long;

ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; ++cs) {
        ll n, K, mod;
        cin >> n >> K >> mod;

        ll sum = 0, x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            sum = (sum + x) % mod;
        }

        ll res = (K % mod) * sum % mod;
        res = res * mod_pow(n, K - 1, mod) % mod;

        printf("Case %d: %llu\n", cs, res);
    }

    return 0;
}