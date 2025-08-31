#include<bits/stdc++.h>

using namespace std;

void solve(){
    int x;
    cin>>x;
    for(int i = 0 ; i<30 ; i++){
        for(int j = 0 ; j<30 ; j++){
            int y = (1<<i) | (1<<j);
            if(y<x&&((x+y)>(x^y)) and (((x^y) + y) > x) and ((x^y)+x > y)){
                cout<<y<<endl;
                return;
            }
        }
    }
    cout<< -1<<endl;
}



int main(){

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}