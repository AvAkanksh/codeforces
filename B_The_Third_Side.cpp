#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        sum+=x;
    }
    cout<<sum-n+1<<endl;

}

int main(){

    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}