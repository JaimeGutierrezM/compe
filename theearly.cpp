#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

inline bool IsPerfect(int p)
{
    return p == 2 || p == 3 || p == 5 || p == 7 ||
        p == 13 || p == 17 || p == 19 || p == 31;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;
    int count = 0;

    while (getline(ss, token, ',') && count < N)
    {
        int p = stoi(token);
        if (IsPerfect(p))
            cout << "Yes\n";
        else
            cout << "No\n";
        ++count;
    }

    return 0;
}
