#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,p;
    
    cin>>n>>m>>p;
    int addOne = 0;
    if(n>=m){
        addOne = 1;
    }
    cout<< (n-m)/p +addOne<<endl;
    return 0;
}