#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        x--;
        v[x] = i;
    }
    int count = 1;
    for(int i=1 ; i<n ; i++){
        if(v[i]<v[i-1]){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t  = 1;
    while (t--){
        solve();
    }
    return 0;
}

// [0,1,2,3,4]
// [2,1,4,0,3]


// [0,1,2,3,4]
// [4,3,2,1,0]