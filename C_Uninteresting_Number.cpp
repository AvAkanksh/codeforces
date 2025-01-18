#include<bits/stdc++.h>
using namespace std;

void solve(long long n){
    int count = 0;
    int noOf2s = 0;
    int noOf3s = 0;
    while(n>0){
        count+=n%10;
        if(n%10==2){
            noOf2s++;
        }else if(n%10==3){
            noOf3s++;
        }
        n/=10;
    }
    if(count%9==0){
        cout<<"YES"<<endl;
        return;
    }else{
        for(int i = 0 ; i<=noOf2s ; i++){
            for(int j = 0 ;  j<=noOf3s ; j++){
                if((i*2+j*6+count)%9==0){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        solve(n);
    }
    return 0;
}