#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    
    for(int i = 1 ; i<=t ; i++){
        int n ;
        cin >> n;
        for(int j = 1 ; j<=n ;j++){
            cout<<(2*j)-1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}