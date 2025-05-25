#include<bits/stdc++.h>

using namespace std;

void solve(){
    int l,r,d,u;
    cin >> l >> r >> d >> u;
    if(l==r and d==u and l==d ){
        cout << "Yes" << endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}