#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, newString;
    cin>>s;

    size_t end = s.find_last_not_of('0'); // Find the last character that's not '0'
    if (end == string::npos) {
        cout<<"Yes"<<endl;
        return 0;
    }
    newString = s.substr(0, end + 1);
    string reverseString = newString;
    reverse(reverseString.begin(), reverseString.end());
    if(newString == reverseString){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}