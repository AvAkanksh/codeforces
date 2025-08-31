#include<bits/stdc++.h>
using namespace std;

void lcm(int a,int b){
    int res = (a*b)/__gcd(a,b);
    cout<<res<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a;
        int b;
        cin>>a>>b;
        lcm(a,b);
    }
    return 0;
}