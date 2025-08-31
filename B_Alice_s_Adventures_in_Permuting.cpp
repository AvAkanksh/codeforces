#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n,b,c;
    std::cin>>n>>b>>c;
    long long ans = -1;

    if(b!=0){
        ans = n - (c<n?(n-c-1)/b+1:0);
    }else if(c>=n){
        ans = n;
    }else if(c<=n-3){
        ans = -1;
    }else{
        ans = n-1;
    }
    cout<<ans<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}