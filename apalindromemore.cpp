//apalindromemore
#include <iostream>
#include <string>
#include <vector>

#pragma gcc optimize("O3")

using namespace std;

bool subpalindrome(const string &s, size_t l, size_t r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        } else {
            l++;
            r--;
        }
    }
    return true;
}

bool alindrome(const string &s) {
    size_t length = s.size() - 1;
    for (size_t i = 0; i < length; i++) {
        if (subpalindrome(s, 0, i) && subpalindrome(s, i + 1, length)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        size_t length = s.size() - 1;

        if (alindrome(s)) {
            cout << "alindrome" << endl;
        } else if (subpalindrome(s, 0, length)) {
            cout << "palindrome" << endl;
        } else {
            cout << "simple" << endl;
        }
    }

    return 0;
}