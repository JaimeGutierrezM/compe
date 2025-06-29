//youhave
#include<bits/stdc++.h>
using namespace std;
int main(){
    char al[101];
    long long a,b,c,n;
    memset(al,0,sizeof(al));
    while(scanf("%s",&al)!=EOF){
        a=strlen(al);
        b=c=0;
        for(int i=1;i<=a;i++)
            if(al[i-1]=='0'){
                c++;
                if(al[i%a]=='0')
                    b++;
            }
        if(b*a>c*c){
            cout<<"SHOOT"<<endl;
            continue;
        }
        if(a*b==c*c){
            cout<<"EQUAL"<<endl;
            continue;
        }
        cout<<"ROTATE"<<endl;
        memset(al,0,sizeof(al));
    }
    return 0;
}