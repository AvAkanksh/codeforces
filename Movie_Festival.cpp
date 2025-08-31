#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool mycompare(pair<ll,ll> a, pair<ll,ll> b){
    return a.second < b.second;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(),mycompare);
    int ans = 0;
    ll end = 0;
    for(auto i : v){
        if(i.first>=end){
            ans++;
            end = i.second;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}