#define ll long long
#include <bits/stdc++.h>
using namespace std;

string check1100(string s, int idx, int v){
    s[idx-1] = to_string(v)[0];
    string newString = s;
    for(int i = max(0,idx-4) ; i<idx+4; i++){
        if(newString[i]=='1' and newString[i+1]=='1' and newString[i+2]=='0' and newString[i+3]=='0'){
            cout<<"YES"<<"\n";
            return newString;
        }
    }
    cout<<"NO"<<"\n";
    return newString;

}

void solve(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    for(int i = 0 ; i < q ; i++){
        int idx,v;
        cin>>idx>>v;
        s = check1100(s,idx,v);
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