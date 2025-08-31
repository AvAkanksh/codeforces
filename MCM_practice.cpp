#include<bits/stdc++.h>

using namespace std;

int static dp[100][100];
int solve(int arr[], int i , int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    // cout<<"i : "<<i<<"| j : "<<j<<endl;
    for(int k = i ; k<j ; k++){
        // cout<<"i : "<<i<<"| j : "<<j<<"| k : "<<k<<endl;
        int left = solve(arr,i,k);
        int right = solve(arr,k+1,j);
        // cout<<"left : "<<left<<"| right : "<<right<<endl;
        int temp_ans = left + right + arr[i-1]*arr[k]*arr[j];
        // cout<<"temp_ans: "<<temp_ans<<endl;
        // cout<<"----------"<<endl;
        ans = min(ans,temp_ans);
        
    }
    return dp[i][j] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int arr[] = {40,20,30,10,30,10,40,20,30,10,30,10,30,10,30,10,30,10,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<solve(arr,1,n-1)<<endl;

    return 0;
}