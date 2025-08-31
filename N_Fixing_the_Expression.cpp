#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int first = s[0]-'0';
    char comparator = s[1];
    int second = s[2]-'0';
    if(comparator == '<'){
        if(first<second){
            cout<<s<<endl;
            return;
        }else{
            if(first == second){
                s = to_string(first) + "=" + to_string(second);
                cout<<s<<endl;
                return;
            }else{
                s = to_string(first) + ">" + to_string(second);
                cout<<s<<endl;
                return;
            }
        }
    }
    else if(comparator == '='){
        if(first == second){
            cout<<s<<endl;
            return;
        }else if(first<second){
            s = to_string(first) + "<" + to_string(second);
            cout<<s<<endl;
            return;
        }else{
            s = to_string(first) + ">" + to_string(second);
            cout<<s<<endl;
            return;
        }
    }
    else{
        if(first>second){
            cout<<s<<endl;
            return;
        }else{
            if(first == second){
                s = to_string(first) + "=" + to_string(second);
                cout<<s<<endl;
                return;
            }else{
                s = to_string(first) + "<" + to_string(second);
                cout<<s<<endl;
                return;
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        // cout<<t<<endl;
        solve();
    }
    return 0;
}
