#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    string s;
    cin>>n>>m>>k>>s;
    int ans = 0;
    int i = 0;
    while(i<=n-m){
        if(s.substr(i,m) == string(m,'0')){
            s = s.substr(0,i+m-1) + string(k,'1') + s.substr(i+k);
            ans++;
            i+=m+k;
        }else{
            i++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}