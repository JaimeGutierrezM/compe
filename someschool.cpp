//someschool
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m, A[50], sum[50];
    int testcase, cases = 0;
    scanf_s("%d", &testcase);
    while (testcase--) {
        n = 5;
        m = n * (n - 1) / 2;

        for (int i = 0; i < m; i++)
            scanf_s("%d", &sum[i]);
        sort(sum, sum + m);

        printf("Case %d:", ++cases);

        multiset<int> oRB;
        for (int i = 2; i < m; i++)
            oRB.insert(sum[i]);
        int idx, flag = 0;
        for (int i = 2; i < m; i++) { // A[1]+A[2] = sum[i]
            if ((sum[0] + sum[1] + sum[i]) % 2)
                continue;
            int tmp = (sum[0] + sum[1] + sum[i]) / 2;
            A[0] = tmp - sum[i];
            A[1] = tmp - sum[1];
            A[2] = tmp - sum[0];
            multiset<int> RB; // copy
            multiset<int>::iterator it;
            RB = oRB;
            it = RB.find(sum[i]);
            RB.erase(it);
            int pass = 1;
            for (int j = 3; j < n; j++) {
                it = RB.begin();// get min
                A[j] = (*it) - A[0];
                RB.erase(it);
                int ok = 1;
                for (int k = 1; k < j; k++) { // delete A[j]+A[0-(j-1)]
                    int tmp = A[j] + A[k];
                    it = RB.find(tmp);
                    if (it == RB.end()) {
                        ok = 0;
                        break;
                    }
                    RB.erase(it);
                }
                if (!ok) {
                    pass = 0;
                    break;
                }
            }
            if (pass) {// output ans
                flag = 1;
                for (int j = 0; j < n; j++)
                    printf(" %d", A[j]);
                puts("");
                break;
            }
        }
        if (!flag)
            puts("Impossible");
    }
    return 0;
}