//letus
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#define max 100001
 
using namespace std;
void generate();
long int dividor[max], sumdividor[max];
 
void generate()
{
    long int i, j, k;
    for(i=1;i<=max;i++)
    {
        dividor[i]=1;
        sumdividor[i]=1;
    }
 
    for(i=2;i<=max;i++)
    {
        dividor[i]+=1;
        sumdividor[i]+=i;
        for(j=i+i;j<=max;j=j+i)
        {
           dividor[j]+=1;
           sumdividor[j]+=i;
        }
    }
}
 
int main()
{
    long int t, a, b, i, j, k, m, div;
    long long int sum;
    generate();
    while(scanf("%ld",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            div=0;
            sum=0;
            scanf("%ld%ld%ld", &a,&b,&k);
            for(j=a;j<=b;j++)
            {
                if(j%k==0)
                {
                    div+=dividor[j];
                    sum+=sumdividor[j];
                }
            }
            printf("%ld %lld\n", div, sum);
        }
    }
    return 0;
}