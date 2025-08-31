#include<bits/stdc++.h>

using namespace std;

void build(int idx, int start, int end, vector<int>&v, vector<int>&st ){
    if(start==end){
        st[idx] = v[start]; 
        return;
    }
    int mid = (start+end)/2;
    build(2*idx+1 , start, mid,v,st);
    build(2*idx+2, mid+1, end,v,st);
    st[idx] = st[2*idx+1] + st[2*idx+2];
}

void print(vector<int>&st){
    for(auto x:st){
        cout<<x<<" ";
    }
    cout<<endl;
}

void update(int curr,int updateIdx, int updateVal, int start, int end, vector<int>&v, vector<int>&st){
    if(start==end && start==updateIdx){
        v[updateIdx] = updateVal;
        st[curr] = updateVal;
        return;
    }
    int mid = (start+end)/2;
    if(updateIdx<=mid){
        update(2*curr+1, updateIdx, updateVal, start ,mid, v,st);
    }else{
        update(2*curr+2, updateIdx, updateVal, mid+1 ,end, v,st);
    }
    st[curr] = st[2*curr+1] + st[2*curr+2];
}

int query(int idx, int start, int end, int l, int r, vector<int>&st){
    if(start>r || end <l){
        return 0;
    }
    if(l>=start and r <= end){
        return st[idx];
    }
    int mid = (l+r)/2;
    return query(2*idx+1,start,end,l,mid,st) + query(2*idx+2,start,end,mid+1,r,st);
}

int main(){
    vector<int> v= {1,2,3,4,5,6,7,8};
    int n = v.size();
    vector<int> st(2*n-1);
    build(0,0,n-1,v,st);
    print(st);
    int updateIdx = 2; //0 based index;
    int updateVal = 10;
    update(0,updateIdx,updateVal,0,n-1,v,st);
    print(v);
    print(st);
    int start = 2;
    int end = 6;
    cout<<query(0,start,end,0,n-1,st)<<endl;
    return 0;
}