#include <iostream>
using namespace std;

long long n,a,b;

long long f(long long x)
{
    return(a * ( (x*x) % n ) + b ) % n;
}

int main()
{
    
    while(cin>>n && n)
    {
        cin >> a >> b;
        if(n==1)
        {
            cout<< "0" << endl;
            continue;
        }

        long long t = f(0), h = f(f(0)), l=1;
        
        while(t!=h)
        {
            t = f(t);
            h = f(f(h));
        }
        
        
        h = f(t);
        
        while(t!=h)
        {
            h = f(h);
            l++;
        }
        
        
        cout << n-l << "\n";
    }
}