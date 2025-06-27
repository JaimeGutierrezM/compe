#include <iostream>
using namespace std;

int main() {
    char s[13];
    int n, m;

    while (cin >> s >> n >> m) 
    {
        int arr[n][m][m]; 
        int dp[n][m];
        int ans = 2e9;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = i ? 2e9 : 0;
            }
                
        }
            

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    cin >> arr[i][j][k];
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    if (dp[i][k] > dp[i-1][j] + arr[i][j][k])
                    {
                        dp[i][k] = dp[i-1][j] + arr[i][j][k];
                    }
                        
                }
                    
            }
                
        }
            

        for (int i = 0; i < m; i++)
        {
            if (ans > dp[n-1][i])
            {
                ans = dp[n-1][i];
            }
        }
           
        cout << s << endl << ans + 2 * (n - 1) << endl;
    }
    return 0;
}