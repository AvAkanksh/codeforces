#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    bool flag = true;
    for(int i = 1 ; i<n ;i++){
        if(abs(v[i]-v[i-1])==5 || abs(v[i]-v[i-1])==7){
            continue;
        }
        flag = false;
        break;
    }
    if(flag){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
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