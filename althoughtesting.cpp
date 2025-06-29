//althoughtesting
#include <stdio.h>
#include <string.h>
char stmt[10005][100];
int n, i;
long long calc() {
    long long ret = 0, tmp = 0;
    if(!strcmp(stmt[i], "IF")) {
        i++;
        tmp = 1;
        while(true) {
            if(!strcmp(stmt[i], "IF"))
                tmp *= calc();
            else
                break;
        }
        ret += tmp;
    }
    if(!strcmp(stmt[i], "ELSE")) {
        i++;
        tmp = 1;
        while(true) {
            if(!strcmp(stmt[i], "IF"))
                tmp *= calc();
            else
                break;
        }
        ret += tmp;
    }
    i++;
    return ret;
}
int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        n = 0;
        while(scanf("%s", &stmt[n]) == 1) {
            if(!strcmp(stmt[n], "ENDPROGRAM"))
                break;
            if(!strcmp(stmt[n], "IF"))
                n++;
            else if(!strcmp(stmt[n], "ELSE"))
                n++;
            else if(!strcmp(stmt[n], "END_IF"))
                n++;
        }
        n++;
        i = 0;
        long long ret = 1;
        while(i < n-1)
            ret *= calc();
        printf("%lld\n", ret);
    }
    return 0;
}