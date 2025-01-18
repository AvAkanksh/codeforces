#include<bits/stdc++.h>
using namespace std;

float solve(){
    float radius;
    cin>>radius;
    return 4*radius*radius-M_PI*radius*radius;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 1 ; i<=t ;i++){
        float value = solve();
        printf("Case %d: %.2f\n",i, value);
    }    
    return 0;
}