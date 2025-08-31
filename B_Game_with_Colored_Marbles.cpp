#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    int alice_score = 0;
    int bob_score = 0;
    int flag = true;
    for(auto x : mp){
        if(x.second==1){
            if(flag){
                alice_score += 2;
                flag = false;
            }else{
                bob_score += 2;
                flag = true;
            }
        }
        else{
            alice_score+=1;
            bob_score+=1;
        }
    }
    cout<<alice_score<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}