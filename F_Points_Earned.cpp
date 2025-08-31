#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin>>n;

    int yen_500 = n/500;
    n = n%500;
    int yen_5 = n/5;
    n = n%5;
    cout<<1000*yen_500+5*yen_5<<endl;
    return 0;

}