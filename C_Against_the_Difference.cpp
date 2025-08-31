#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int findNextIdx(int idx, int value, vector<int>v){
    int idx_idx = lower_bound(v.begin(),v.end(),idx)-v.begin();
    // cout<<"idx_idx : "<<idx_idx<<endl;
    int newIdx = value -1+ idx_idx;
    // cout<<"newIdx: "<<newIdx<<endl;
    // cout<<"v.size() : "<<v.size()<<endl;
    if(newIdx>=v.size()){
        return -1;
    }else{
        return v[newIdx];
    }
}

int helper(int idx,int sum , vector<int>&v, unordered_map<int,vector<int>>&mp){
    if(idx>=v.size()){
        return 0;
    }
    int nextIdx = findNextIdx(idx,v[idx],mp[v[idx]]);
    // cout<<"nextIdx : "<<nextIdx<<endl;
    int taken = 0;
    if(nextIdx !=-1 ){
        // cout<<"HI"<<endl;
        taken =  v[idx] + helper(nextIdx,sum,v,mp);
    }
    int skip = helper(idx+1,sum, v,mp);

    return max(taken,skip);
}

void solve()
{
    int n ;
    cin>>n;
    vector<int> v(n);
    unordered_map<int,vector<int>> mp;
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
        if(mp.find(v[i])==mp.end()){
            mp[v[i]] = {i};
        }else{
            mp[v[i]].push_back(i);
        }
    }
    // cout<<1<<endl;
    // for(auto x : mp){
    //     cout<<x.first<<" : ";
    //     for(auto y : x.second){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    //     cout<<"--------"<<endl;
    // }
    cout<<helper(0,0,v,mp)<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
