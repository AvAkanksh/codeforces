#define ll long long
#include <bits/stdc++.h>
using namespace std;

// void solve(){
//     string s;
//     cin>>s;
//     sort(s.begin(),s.end());
//     vector<string> v;
//     v.push_back(s);
//     while(next_permutation(s.begin(),s.end())){
//         v.push_back(s);
//     }
//     cout<<v.size()<<'\n';
//     for(auto i : v){
//         cout<<i<<"\n";
//     }
// }

set<string> ss;

void recursion(string s, int idx){
    if(idx == s.size()-1){
        ss.insert(s);
        return;
    }
    for(int i = idx ; i<s.size() ; i++){
        swap(s[idx],s[i]);
        recursion(s,idx+1);
        swap(s[idx],s[i]);
    }
}

void solve(){
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    recursion(s,0);
    cout<<ss.size()<<'\n';
    for(auto x : ss){
        cout<<x<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}