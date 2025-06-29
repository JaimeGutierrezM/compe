//ararebook
#include <iostream>
#include <vector>
using namespace std;


vector<int> graph[26];
bool check[26];
string result;


void dfs(int u) 
{
    check[u] = true;

    for (int v : graph[u])
    {
        if (!check[v]) dfs(v);
    }
        
    result += (char)(u + 'A');
}

int main() {

    string s1, s2;
    cin >> s1;
    while (cin >> s2 && s2 != "#")
    {
        for (int i = 0; i < s1.size() && i < s2.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                graph[s1[i] - 'A'].push_back(s2[i] - 'A');
                break;
            }
        }
            
        s1 = s2;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (!check[i] && graph[i].size()) dfs(i);
    }
        
    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i];
    } 

    cout << endl ;
}