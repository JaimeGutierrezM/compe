//theearly
#include <iostream>

using namespace std;

inline bool IsPerfect(int p)
{
  
    return p == 2 || p == 3 || p == 5 || p == 7 ||
        p == 13 || p == 17;
}

int main()
{
    int N;
    cin >> N;
    
    char junk;
    for (int i = 0; i < N; ++i)
    {
        int p;
        cin >> p >> junk;
        
        if (IsPerfect(p))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
