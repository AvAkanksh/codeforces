#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int passengers_at_busstop = 0;

    while(n--){
        char event;
        int passengers_or_freeseats;
        cin>>event>>passengers_or_freeseats;
        if(event == 'P'){
            passengers_at_busstop += passengers_or_freeseats;
        }else{
            bool flag = passengers_or_freeseats - passengers_at_busstop>0?true:false;
            if(flag){
                passengers_at_busstop = 0;
            }else{
                passengers_at_busstop -= passengers_or_freeseats;
            }
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }

    }

    return 0;
}