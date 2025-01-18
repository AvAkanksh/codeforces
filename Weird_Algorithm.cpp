#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    ll n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n = n/2;
        }else{
            n = 3*n+1;
        }
    }
    cout<<"1"<<"\n";
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