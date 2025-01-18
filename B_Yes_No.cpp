#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long total = 0;
    while(n>0){
        if(total%9==0){
            total = 0;
        }
        total += n%10;
        n/=10;
    }
    if(total%9==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}