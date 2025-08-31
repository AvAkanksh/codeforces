#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool my_compare(pair<int,int> p1,pair<int,int> p2){
    if(p1.first == p2.first){
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

void solve(){
    int n;
    cin >>n;
    if(n == 1){
        string s;
        cin>>s;
        cout<<1<<endl;
        return;
    }
    vector<pair<int,int>> v;
    for(int i = 1 ; i<=n ; i++){
        string s;
        cin>>s;
        int count=0;
        for(auto c : s){
            if(c=='1'){
                count++;
            }
        }
        v.push_back({count,i});
    }
    sort(v.begin(),v.end(),my_compare);
    for(auto i : v){
        cout<<i.second<<" ";
    }
    cout<<endl;


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