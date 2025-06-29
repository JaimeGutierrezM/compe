//probabilityhas
#include<bits/stdc++.h>
using namespace std;
int main(){
    int kase;
    cin>>kase;
    while(kase--){
        double n,p,i;
        cin>>n>>p>>i;
        double q=1-p;
        if(p==0){
            cout<<"0.0000"<<endl;
            continue;
        }
        printf("%.4lf\n",(pow(q,i-1)*p)/(1-(pow(q,n)))); 
    }
}
