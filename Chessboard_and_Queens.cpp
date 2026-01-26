#include<bits/stdc++.h>
#include<chrono>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define INF 1e18
#define MOD 1000000007
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T, custom_hash> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V,custom_hash> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

bool checkIsSafe(vector<string>&cb, int row, int col){
    if(cb[row][col]=='*') return false;
    for(int i =0 ; i<col ; i++){
        if(cb[row][i]=='q')return false;
    }

    for(int i = row-1 , j = col-1 ; i>=0 and j>=0 ; i-- , j--){
        if(cb[i][j]=='q')return false;
    }

    for(int i = row+1 , j = col-1 ; i<8 and j>=0 ; i++ , j--){
        if(cb[i][j]=='q')return false;
    }
    return true;
}

void countConfigurations(vector<string> &cb, int& ans, int col){
    if(col==8){
        ans++;
        return;
    }
    for(int row = 0 ; row<8 ; row++){
        if(checkIsSafe(cb,row,col)){
            cb[row][col] = 'q';
            countConfigurations(cb,ans,col+1);
            cb[row][col] = '.';
        }
    }
}

void solve(){
    int ans = 0;
    vector<string> cb(8);
    for(int i = 0; i<8 ; i++){
        cin>>cb[i];
    }
    int col = 0;
    countConfigurations(cb,ans,col);
    cout<<ans<<endl;
}
int main()
{
    fastio();
    ll t;
    // cin >> t;
    t =1;
    for (int zx = 1; zx <= t; zx++)
    {
        // cout << "Case #" << zx << ": ";
        solve();
    }
    return 0;
}