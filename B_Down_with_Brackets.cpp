#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int count = 0;
    stack<char> st;
    for(auto x : s){
        if(x=='('){
            st.push('(');
        }else{
            st.pop();
        }

        if(st.empty()){
            count++;
        }
    }
    if(count>1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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