#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    vector<int> a(n);
    for(int i = 0 ; i<n; i++){
        cin>>a[i];
    }
    int maxx = 0;
    int maxx_num = 0;
    map<int,int> mp;
    for(int i = 0 ; i<n ; i++){
        mp[a[i]] = mp[a[i]-1] +1;
        if(mp[a[i]]>maxx){
            maxx = mp[a[i]];
            maxx_num = a[i];
        }
    }
    vector<int> ans;
    for(int i = n-1 ; i>=0 ; i--){
        if(a[i]==maxx_num){
            ans.push_back(i);
            maxx_num--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i+1<<" ";
    }
    return 0;
}