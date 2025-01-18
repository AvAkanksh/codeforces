// // #include<bits/stdc++.h>
// // using namespace std;

// // void printCoordinates(int first, int second, int third, int fourth){
// //     cout<<"YES"<<endl;
// //     cout<<first<<" "<<second<<" "<<first<<" "<<fourth<<" "<<third<<" "<<second<<" "<<third<<" "<<fourth<<endl;
// // }

// // void solve(){
// //     int n;
// //     cin>>n;
// //     map<int,int> mp;
// //     while(n--){
// //         int x;
// //         cin>>x;
// //         mp[x]++;
// //     }
// //     int first_element = -1;
// //     int second_element = -1;
// //     int third_element = -1;
// //     int fourth_element = -1;
// //     int first,second,third,fourth;

// //     for(auto x : mp){
// //         if(x.second>=2){
// //             if(first_element == -1){
// //                 first = x.first;
// //                 first_element = 1;
// //             }else if(second_element == -1){
// //                 second = x.first;
// //                 second_element = 1;
// //             }else if(third_element == -1){
// //                 third = x.first;
// //                 third_element = 1;
// //             }else if(fourth_element == -1){
// //                 fourth = x.first;
// //                 fourth_element = 1;
// //             }else{
// //                 third = fourth;
// //                 fourth = x.first;
// //             }
// //         }
// //     }
// //     if(first_element == -1 || second_element == -1 || third_element == -1 || fourth_element == -1){
// //         cout<<"NO"<<endl;
// //         return;
// //     }
// //     printCoordinates(first,second,third,fourth);
// // }

// // int main(){
// //     std::ios::sync_with_stdio(false);
// //     std::cin.tie(nullptr);

// //     int t;
// //     std::cin>>t;
// //     while(t--){
// //         solve();
// //     }

// //     return 0;
// // }



#include<bits/stdc++.h>
using namespace std;

void printCoordinates(vector<int>v){
    cout<<"YES"<<endl;
    int x1 = v[0];
    int y1 = v[2];
    int x2 = v[4];
    int y2 = v[6];
    cout<<x1<<" "<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        mp[x]++;
        if(mp[x]%2==0){
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    if(v.size()<4){
        cout<<"NO"<<endl;
        return;
    }
    int s = v.size();
    printCoordinates({v[0],v[0],v[1],v[1],v[s-2],v[s-2],v[s-1],v[s-1]});
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}



