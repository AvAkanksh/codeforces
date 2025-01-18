#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , m;
    cin>>n>>m;

    int ans = 0;
    int x_curr = -1, y_curr =-1;
    int x_min = 0;
    int y_min = 0;
    int x_max = 0;
    int y_max = 0;
    for(int i = 0 ; i<n ; i++){
        int x,y;
        cin>>x>>y;
        if(x_curr == -1 && y_curr == -1){
            x_curr = x;
            y_curr = y;
            x_min = x;
            y_min = y;
            x_max = x;
            y_max = y;
        }else{
            x_curr += x;
            y_curr += y;
        }
        x_min = min(x_min,x_curr);
        y_min = min(y_min,y_curr);
        x_max = max(x_max,x_curr);
        y_max = max(y_max,y_curr);
    }
    // cout<<x_min<<" "<<y_min<<" "<<x_max<<" "<<y_max<<"\n";
    cout<<2*(x_max+m - x_min + y_max+m - y_min)<<"\n";
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