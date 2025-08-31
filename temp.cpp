#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    unordered_map<int,vector<pair<int,int>>> p;
    unordered_map<int,vector<pair<int,int>>> s;

    for(int i=2 ; i<100 ; i++){
        for (int j = i+1 ; j < 100 ;j++){
            p[i*j].push_back({i,j});
        }
    }
    for(int i=2 ; i<100 ; i++){
        for (int j = i+1 ; j < 100 ;j++){
            s[i+j].push_back({i*j,p[i*j].size()});
        }
    }
    for(auto it = s.begin() ; it!=s.end();){
        bool flag = true;
        for(int i = 0 ; i<(it->second).size() ; i++){
            if(it->second[i].second<2){
                flag = false;
                break;
            }
        }
        if(!flag){
            it = s.erase(it);
        }else{
            it++;
        }
        
    }
    unordered_map<int,int> freq;
    cout<<"---------"<<endl;
    for(auto x : s){
        cout<<x.first<<": ";
        for(auto y : x.second){
            freq[y.first]++;
            cout<<"("<<y.first<<","<<y.second<<") ";
        }
        cout<<endl;
    }
    cout<<s.size()<<endl;
    cout<<"--------"<<endl;
    int sum = -1;
    int prod = -1;
        for(auto x : s){
        cout<<x.first<<": ";
        int count = 0 ;
        int likelyProd = -1;
        for(auto y : x.second){
            cout<<"("<<y.first<<","<<freq[y.first]<<") ";
            if(freq[y.first]==1){
                count++;
                likelyProd = y.first;
            }
        }
        cout<<endl;
        if(count==1){
            sum = x.first;
            prod = likelyProd;
        }
    }

    cout<<"The required Sum :"<<sum<<" and Product is : "<<prod<<endl;
}
int main()
{
    //     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
