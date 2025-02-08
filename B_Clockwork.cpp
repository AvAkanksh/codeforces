#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    // vector<pair<int,int>> a(n);
    vector<int> a(n);
    bool flag = true;
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];

        int required = 2*(max(i,n-i-1))+1;
        if(flag and a[i]<required){
            flag = false;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}