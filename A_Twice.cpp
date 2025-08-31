#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin >>n;
    unordered_map<int,int> mp;
    int ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(mp[x]==1){
            mp[x] = 0;
            ans++;
        }else{
            mp[x] = 1;
        }
    }
    cout<<ans<<endl;
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