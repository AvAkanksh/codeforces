#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--){
        int n ;
        cin>>n;
        unordered_map<int,int> mp;
        for(int i = 0 ; i<n ; i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        int total = n-2;
        for(int i = 1 ; i<=n; i++){
            if(i == total/i){
                if(mp[i]>=2){
                    cout<<i<<" "<<i<<endl;
                    break;
                }
            }
            else if(mp[i] and mp[total/i] and (total%i==0)){
                cout<<i<<" "<<(total)/i<<endl;
                break;
            }
        }
    }
    return 0;
}