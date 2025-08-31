#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
    ll ans=0;
    int last ;
    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        if(i>0){
            if(last>x){
                ans += last - x;
            }else{
                last = x;
            }
        }
        else{
            last = x;
        }
    }
    cout<<ans<<"\n";
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