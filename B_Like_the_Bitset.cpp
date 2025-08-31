#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n ,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> p(n,0);
    int i = 1 ; 
    for(int j = 0 ; j<n ; j++){
        if(s[j]=='1'){
            p[j] = i;
            i++;
        }
    }
    for(int j = 0 ; j< n ; j++){
        if(s[j]=='0'){
            p[j] = i;
            i++;
        }
    }
    bool flag = true;
    for(int i = 0 ; i<n ; i++){
        if(s[i]=='1'){
            int max_idx = max(i-k+1,0);
            for(int j =max(i-k+1,0) ; j<= i ; j++){
                if(p[max_idx]<p[j]){
                    max_idx = j;
                }
            }
            if(i==max_idx and i!=0){
                // cout<<"max_idx:"<<max_idx<<endl;
                cout<<"NO"<<endl;
                return;
            }
            max_idx = i;
            for(int j =i ; j<= min(n-1,i+k-1) ; j++){
                if(p[max_idx]<p[j]){
                    max_idx = j;
                }
            }
            if(i==max_idx and i!=n-1){
                // cout<<"max_idx:"<<max_idx<<endl;
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0 ; i< n ; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
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
