//intelevision
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{    
    int NCOWS, NCARS, NSHOW;
    while (cin >> NCOWS >> NCARS >> NSHOW)
    {
        
        cout << setprecision(5)
             << fixed
             << ((double)NCARS * (NCOWS + NCARS - 1)) / ((NCOWS + NCARS) * (NCOWS + NCARS - NSHOW - 1))
             << endl;
    }
    return 0;
}