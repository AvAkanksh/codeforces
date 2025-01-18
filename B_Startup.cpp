#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(k,0);
    for(int i = 0; i < k; i++){
        int b,c;
        cin >> b>>c;
        arr[b-1] += c;
    }
    sort(arr.begin(),arr.end(),greater<>());
    int ans = 0;
    int iterate = min(n,k);
    // cout<<"iterate = "<<iterate<<endl;
    for(int i = 0 ; i<iterate; i++){
        ans += arr[i];
    }
    cout<<ans<<endl;
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