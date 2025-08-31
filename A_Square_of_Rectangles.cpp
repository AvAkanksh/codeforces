#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l1,l2,l3,b1,b2,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        bool flag = false;
        int max_val = max(l1,b1);
        if(max_val*max_val == (l1*b1+l2*b2+l3*b3)){
            if(l1>b1){
                if(((l1==l2) and (l2==l3) and (b1+b2+b3==l1)) or (l1==l2+l3 and b3==b2 and b1+b2==l1)){
                    flag = true;
                }
            }else{
                if(((b1==b2) and (b2==b3) and (l1+l2+l3==b1)) or (b1==b2+b3 and l3==l2 and l1+l2==b1)){
                    flag = true;
                }
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}