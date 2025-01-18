#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n,m,r,c;
    cin>>n>>m>>r>>c;
    long long ans = n*m - ((r-1)*m + c) + (n-r)*(m-1) ; 
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}