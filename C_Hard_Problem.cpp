#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, a, b, c;
    cin>>m>>a>>b>>c;
    int ans = min(m,a) + min(m,b) + min(2*m-min(m,a)-min(m,b),c);
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