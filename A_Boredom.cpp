#include<bits/stdc++.h>

using namespace std;
vector<long long> a(static_cast<int>(1e5)+1,0);
vector<long long> b(static_cast<int>(1e5)+1,0);
vector<long long> dp(static_cast<int>(1e5)+1,0);




void solve(){
    int n;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        long long x;
        cin>>x;
        a[i] = x;
        b[x]++;
    }
    dp[1] = b[1];
    for(int i = 2 ; i<1e5+1; i++){
        dp[i] = max(dp[i-1],dp[i-2]+b[i]*i);
    }
    cout<<dp[100000];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;

}