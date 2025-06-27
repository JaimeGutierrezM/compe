#include <iostream>
#include <algorithm>
using namespace std;

struct E 
{
    int x, y, v;
    E(int a=0, int b=0, int c=0) : x(a), y(b), v(c) {}
    bool operator<(const E &a) const { return v < a.v; }
};

E D[10005];
int p[1005], ranks[1005];

int findp(int x) 
{ 
    return p[x] == x ? x : p[x] = findp(p[x]); 
}

int joint(int x, int y) 
{
    x = findp(x), y = findp(y);

    if (x == y)
    {
        return 0;
    } 

    if (ranks[x] > ranks[y])
    {  
        ranks[x] += ranks[y];
        p[y] = x;
    }
    
    else
    {
        ranks[y] += ranks[x], p[x] = y;
    } 
    return 1;
}

int kruscal(int n, int m, E D[], int st, int ed, int &mx) 
{
    for (int i = 0; i <= n; i++)
    {
        p[i] = i, ranks[i] = 1;
    }
    for (int i = 0; i < m; i++) 
    {
        if (joint(D[i].x, D[i].y) && findp(st) == findp(ed)) 
        {
            mx = D[i].v;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, x, y, w, a, b, q;

    while (cin >> n >> m && n + m) 
    {
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> w;
            D[i] = {x, y, w};
        } 

        sort(D, D + m);
        cin >> a >> b >> q;

        while (q--) 
        {
            cin >> x >> y;
            int mx, ret = 0x3f3f3f3f;
            for (int i = 0; i < m; i++)
            {
                if (kruscal(n, m - i, D + i, x, y, mx))
                {
                    ret = min(ret, mx - D[i].v);
                } 
                else break;
            }
                
            cout << a + b + ret << '\n';
        }
    }
    return 0;
}