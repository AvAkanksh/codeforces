#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    bool flag = true;
    if(a>=b and a<=2*(b+1) || b>=a and b<=2*(a+1)){
        if(c-a>=d-b and c-a<=2*(d-b+1) || d-b>=c-a and d-b<=2*(c-a+1)){
            flag = false;
            cout<<"YES"<<endl;
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }

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
