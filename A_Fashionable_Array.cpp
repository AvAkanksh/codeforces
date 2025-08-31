#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        int x;
        cin>>x;
        min_val = min(x,min_val);
        max_val = max(x,max_val);        
        a.push_back(x);
    }
    if((min_val+max_val)%2==0){
        cout<< 0<<endl;
        return;
    }
    else{
        sort(a.begin(), a.end());
        int back_count = 0;
        for(int i = n-1 ; i>=0 ; i--){
            if(a[i]%2==a[0]%2){
                break;
            }
            back_count++;
        }
        int front_count = 0;
        for(int i = 0 ; i<n ; i++){
            if(a[i]%2==a[n-1]%2){
                break;
            }
            front_count++;
        }
        cout<< min(front_count,back_count)<<endl;
        return;

    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;

}