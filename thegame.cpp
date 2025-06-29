//thegame
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

vector<int> get_dart_scores() {
    vector<int> scores = { 0, 50 }; 
    for (int i = 1; i <= 20; ++i) {
        scores.push_back(i);     
        scores.push_back(2 * i); 
        scores.push_back(3 * i); 
    }
    sort(scores.begin(), scores.end());
    return scores;
}


ll count_permutations(int a, int b, int c) {
    if (a == b && b == c) return 1; 
    if (a == b || b == c || a == c) return 3; 
    return 6; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    vector<int> scores = get_dart_scores();
    int max_score = 3 * 60; 
    vector<ll> comb(max_score + 1, 0); 
    vector<ll> perm(max_score + 1, 0); 

   
    set<vector<int>> unique_combinations;
    for (int i = 0; i < scores.size(); ++i) {
        for (int j = 0; j < scores.size(); ++j) {
            for (int k = 0; k < scores.size(); ++k) {
                int sum = scores[i] + scores[j] + scores[k];
                if (sum > max_score) continue;
                
                vector<int> triplet = { scores[i], scores[j], scores[k] };
                sort(triplet.begin(), triplet.end());
                if (unique_combinations.insert(triplet).second) {
                    comb[sum]++;
                    perm[sum] += count_permutations(scores[i], scores[j], scores[k]);
                }
            }
        }
    }

    
    while (true) {
        int s;
        cin >> s;
        if (s <= 0) break;

        if (s > max_score || comb[s] == 0) {
            cout << "THE SCORE OF " << s << " CANNOT BE MADE WITH THREE DARTS.\n";
        }
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << s << " IS " << comb[s] << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << s << " IS " << perm[s] << ".\n";
        }
        cout << "**********************************************************************\n";
    }

    cout << "END OF OUTPUT\n";

    return 0;
}