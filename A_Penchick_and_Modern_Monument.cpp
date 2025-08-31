#include<bits/stdc++.h>

using namespace std;

void solve(){
    int ans = 0;
    int n;
    cin>>n;
    vector<int> h;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        h.push_back(x);
    }
    map<int,int> freq;
    int mx = 0;
    for(int i = 0 ; i<n ; i++){
        freq[h[i]]++;
        mx = max(mx, freq[h[i]]);
    }
    cout<<n-mx<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t ;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}