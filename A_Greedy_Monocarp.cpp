#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    long long total = 0;
    for(auto i : a){
        if(total==k){
            cout<<0<<endl;
            return;
        }
        if(total + i > k){
            cout<<k-total<<endl;
            return;
        }
        total+=i;
    }
    if(total==k){
        cout<<0<<endl;
    }
    else{
        cout<<k-total<<endl;
    }
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