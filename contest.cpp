#include<bits/stdc++.h>
using namespace std;

pair<int,int> solveString(string s){
    pair<int,int> effectiveMovement;
    effectiveMovement = {0,0};
    for(auto i:s){
        if(i=='N'){
            effectiveMovement.second++;
        }
        else if(i=='S'){
            effectiveMovement.second--;
        }
        else if(i=='E'){
            effectiveMovement.first++;
        }
        else{
            effectiveMovement.first--;
        }
    }
    return effectiveMovement;
}

string traverse(int a, int b, string s){
    int currX = 0;
    int currY = 0;
    int n = s.length();
    int i = 0;
    while(i<n){
        if(s[i]=='N'){
            currY++;
        }
        else if(s[i]=='S'){
            currY--;
        }
        else if(s[i]=='E'){
            currX++;
        }
        else{
            currX--;
        }
        // cout<<currX<<" "<<currY<<endl;
        if(currX==a && currY==b){
            return "YES";
        }
        i++;
    }
    return "NO";
}

string solve(int n,int a,int b,string s){
    string ans = "NO";
    pair<int,int> movement = solveString(s);
    // cout<<"effective movement: "<<movement.first<<" "<<movement.second<<endl;
    if(movement.first != 0 && movement.second != 0){
        ans = traverse(a,b,s);
        if(ans == "YES"){
            return ans;
        }
        if(a/movement.first == b/movement.second){
            return ans = "YES";
        }
        a = a%movement.first;
        b = b%movement.second;
    }
    ans = traverse(a,b,s);
    return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        string ans = solve(n,a,b,s);
        cout<<ans<<endl;
    }
    return 0;

}