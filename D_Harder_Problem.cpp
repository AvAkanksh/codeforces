#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n,-1);
    
    unordered_set<int> s;
    for(int i = 1; i<=n ; i++){
        s.insert(i);
    }
    vector<int> b(n);
    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        if(a[x-1]==1){
            b[i] = -2;
        }
        else if(a[x-1]==-1){
            a[x-1] = 1;
            b[i] = x;
            s.erase(x);
        }
    }
    for(int i = 0 ; i<n ; i++){
        if(b[i]==-2){
            b[i] = *(s.begin());
            s.erase(s.begin());
        }
    }

    for(int i = 0 ; i<n ; i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";

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