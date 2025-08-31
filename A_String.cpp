#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int count = 0;
    for(auto i: s){
        if(i=='1'){
            count++;
        }
    }
    cout<<count<<endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}