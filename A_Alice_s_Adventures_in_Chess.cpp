#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, a,b;
    std::cin>>n>>a>>b;
    std::string s;
    std::cin>>s;
    int x = 0, y = 0;
    for(int i = 0; i<40 ; i++){
        for(auto c : s){
            if(c == 'N'){
                y++;
            }
            else if(c == 'S'){
                y--;
            }
            else if(c == 'E'){
                x++;
            }
            else{
                x--;
            }
            if(x == a && y == b){
                std::cout<<"YES"<<std::endl;
                return;
            }
        }
    }
    std::cout<<"NO"<<std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;
    while(t--){
        solve();

    }
    return 0;
}