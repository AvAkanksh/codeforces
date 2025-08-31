#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    std::replace(s.begin(),s.end(),'p','s');
    std::replace(s.begin(),s.end(),'q','p');
    std::replace(s.begin(),s.end(),'s','q');
    std::reverse(s.begin(),s.end());
    cout<<s<<"\n";
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