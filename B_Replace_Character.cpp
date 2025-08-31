#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    
    for(int i = 0 ; i<n ; i++){
        mp[s[i]]++;
        minVal = min(minVal,mp[s[i]]);
        maxVal = max(maxVal,mp[s[i]]);
    }

    for(auto x: mp){
        cout<<x.first<<" "<<x.second<<endl;
    }

    char minChar;
    char maxChar;
    bool flag = false;
    if(maxVal - minVal >0){
        flag = true;
    }
    for(auto x : mp){
        if(x.second == minVal and flag){
            minChar = x.first;
        }
        if(x.second == maxVal){
            maxChar = x.first;
            flag = true;
        }
    }
    int change = true;
    for(int i = 0 ; i<n ;i++){
        if(s[i] == minChar and change){
            cout<<maxChar;
            change = false;
        }else{
            cout<<s[i];
        }
    }
    cout<<'\n';
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