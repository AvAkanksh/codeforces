#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ;i<n; i++){
        cin>>v[i];
    }
    for(int i = 1 ; i<n ;i++){
        if(v[i-1]-v[i]==1){
            swap(v[i],v[i-1]);
        }
    }
    if(is_sorted(v.begin(),v.end())){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}