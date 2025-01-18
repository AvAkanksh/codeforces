#define ll long long
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n ;
    cin>>n;
    long long sum = 0;
    int ans  = 0;
    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        sum+=x;
        long long sr = sqrt(sum);
        // cout<<"sr = "<<sr<<"\n";
        // cout<<"sum = "<<sum<<"\n";
        if(sr*sr == sum){
            // cout<<("Perfect Square")<<"\n";
            if((sr-1)%2==0){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin >> t;
while (t--)
{
 solve();
}
return 0;
}