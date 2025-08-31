#define ll long long
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
    if(n*(n+1)/2%2==0){
        cout<<"YES"<<endl;
        vector<int> s1;
        vector<int> s2;
        if(n%2==1){
            for(int i = 1 ; i<=n ; i++){
                if(((i-1)/2)%2 ==0){
                    s1.push_back(i);
                }else{
                    s2.push_back(i);
                }
            }
            cout<<s1.size()<<endl;
            for(auto i = 0 ; i<static_cast<int>(s1.size()) ; i++){
                cout<<s1[i]<<" ";
            }
            cout<<endl;
            cout<<s2.size()<<endl;
            for(auto i = 0 ; i<static_cast<int>(s2.size()) ; i++){
                cout<<s2[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(auto i = 0 ; i< n/2; i++){
                if(i%2 == 0){
                    s1.push_back(i+1);
                    s1.push_back(n-i);
                }else{
                    s2.push_back(i+1);
                    s2.push_back(n-i);
                }
            }
            cout<<s1.size()<<endl;
            for(auto i = 0 ; i<static_cast<int>(s1.size()) ; i++){
                cout<<s1[i]<<" ";
            }
            cout<<endl;
            cout<<s2.size()<<endl;
            for(auto i = 0 ; i<static_cast<int>(s2.size()) ; i++){
                cout<<s2[i]<<" ";
            }
            cout<<endl;

        }
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t = 1;
    while (t--){
        solve();
    }
    return 0;
}