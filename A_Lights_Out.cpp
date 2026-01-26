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

void solve(){
    vector<vector<int>> grid(3, vector<int> (3,1));
    vector<int> dir = {-1,0,1,0};
    for(int i = 0 ; i<3 ; i++){
        for(int j = 0 ; j<3 ; j++){
            int x ;
            cin>>x;
            if(x%2==1){
            grid[i][j]+=1;
            for(int k =0 ; k<4 ; k++)
                if(i+dir[k]>=0 and i+dir[k]<=2 and j+dir[(k+1)%4]>=0 and j+dir[(k+1)%4]<=2){
                    grid[i+dir[k]][j+dir[(k+1)%4]]+=1;
                }
            }
        }
    }
    for(auto x : grid){
        for(auto y : x){
            cout<<y%2;
        }cout<<endl;
    }
}
int main()
{
    fastio();
    ll t;
    // cin >> t;
    t = 1;
    for (int zx = 1; zx <= t; zx++)
    {
        // cout << "Case #" << zx << ": ";
        solve();
    }
    return 0;
}