//thethoughtpolice
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<vector<int>> grafo;
vector<int> numero;
vector<int> bajo;

void busqueda(int u, int p, int &t, set<pair<int, int>> &s) 
{
    numero[u] = bajo[u] = ++t;
    for (auto x : grafo[u]) 
    {
        if (numero[x] == -1) 
        {
            busqueda(x, u, t, s);
            if (bajo[x] > numero[u])
            {
                s.insert({min(u, x), max(u, x)});
            }
            
            bajo[u] = min(bajo[u], bajo[x]);
        }

        else if (x != p)
        {
            bajo[u] = min(bajo[u], numero[x]);
        } 
    }
}

int main() 
{
    while (true) 
    {
        int numero_de_casos, numero_de_enlaces;

        cin >> numero_de_casos >> numero_de_enlaces;

        if ((numero_de_casos == 0) && (numero_de_enlaces == 0)) 
        {
            break;
        }
        

        grafo = vector<vector<int>>(numero_de_casos);
        numero = vector<int>(numero_de_casos, -1);
        bajo = vector<int>(numero_de_casos, -1);

        for (int i = 0; i < numero_de_enlaces; i++) 
        {
            int gi, gj;
            cin >> gi >> gj;
            grafo[gi].push_back(gj);
            grafo[gj].push_back(gi);
        }

        set<pair<int, int>> s;

        int t = 0;

        busqueda(0, -1, t, s);

        cout << s.size();

        for (auto x : s) 
        {
            cout << " " << x.first << " " << x.second;
        }
        cout << endl; 
    }
    
    return 0;
}