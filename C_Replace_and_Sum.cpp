// #if defined(__GNUC__)
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt")
// #endif

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// --- Aliases & Types ---
using ll = long long;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using f128 = __float128;
using lld = long double;

template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

// --- Constants ---
template <class T> constexpr T infty = 0;
template <> constexpr int infty<int> = 1'010'000'000;
template <> constexpr ll infty<ll> = 2'020'000'000'000'000'000;

// --- Macros ---
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c)) 
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR1_R(a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)
#define FOR_R(...) overload4(__VA_ARGS__, FOR3_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) (x).begin(), (x).end()
#define len(x) ll(x.size())
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

namespace fastio {
    static constexpr uint32_t SZ = 1 << 17;
    char ibuf[SZ], obuf[SZ];
    uint32_t pil = 0, pir = 0, por = 0;
    inline void load() { memmove(ibuf, ibuf + pil, pir - pil); pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin); pil = 0; if (pir < SZ) ibuf[pir++] = '\n'; }
    inline void flush() { fwrite(obuf, 1, por, stdout); por = 0; }
    
    void rd(char &c) { if (pil + 32 > pir) load(); do c = ibuf[pil++]; while (isspace(c)); }
    void rd(string &x) { x.clear(); char c; rd(c); do { x += c; if (pil == pir) load(); c = ibuf[pil++]; } while (!isspace(c)); }
    template <typename T> void rd(T &x) { if (pil + 32 > pir) load(); char c; do c = ibuf[pil++]; while (c < '-'); bool m = 0; if constexpr (is_signed_v<T> || is_same_v<T, i128>) { if (c == '-') { m = 1; c = ibuf[pil++]; } } x = 0; while ('0' <= c) { x = x * 10 + (c & 15); c = ibuf[pil++]; } if (m) x = -x; }
    template <class T> void rd(vc<T> &x) { for (auto &d : x) rd(d); }
    void read() {}
    template <class H, class... T> void read(H &h, T &...t) { rd(h); read(t...); }

    void wt(char c) { if (por == SZ) flush(); obuf[por++] = c; }
    void wt(const string &s) { for (char c : s) wt(c); }

    // 1. Handle Arithmetic Types (Integers, Bools, 128-bit)
    template <class T>
    enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u64>, void> wt(T x) {
        if (por > SZ - 32) flush();
        if (x < 0) { obuf[por++] = '-'; x = -x; }
        using U = typename make_unsigned<typename conditional<is_same_v<T, i128>, __int128, T>::type>::type;
        U u = x;
        static char buf[50];
        int len = 0;
        do { buf[len++] = (u % 10) | '0'; u /= 10; } while (u);
        while (len--) obuf[por++] = buf[len];
    }

    // 2. Handle Floating Point
    template <class T>
    enable_if_t<is_floating_point_v<T>, void> wt(T x) {
        if (por > SZ - 32) flush();
        string s = to_string(x); 
        for (char c : s) obuf[por++] = c;
    }

    // 3. Handle Vectors (The one you were missing!)
    template <class T> void wt(const vc<T> &val) { 
        FOR(i, len(val)) { 
            if (i) wt(' '); 
            wt(val[i]); 
        } 
    }

    void print() { wt('\n'); }
    template <class Head, class... Tail> void print(Head &&head, Tail &&...tail) { wt(head); if (sizeof...(Tail)) wt(' '); print(forward<Tail>(tail)...); }
    void __attribute__((destructor)) _d() { flush(); }
}


// --- Global Macros ---
#define INT(...) int __VA_ARGS__; fastio::read(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; fastio::read(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; fastio::read(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); fastio::rd(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); fastio::rd(name)

using fastio::print;

// --- Custom Hash for Maps ---
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};

// --- Debugger ---
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vc<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}"; }
template <class T> void _print(vc<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map<T, V, custom_hash> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

// --- Yes/No Helpers ---
void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }


// --- Solve ---
void solve() {
    INT(N,Q);
    VEC(int,A,N);
    VEC(int,B,N);
    
    FOR_R(i,N){
        chmax(A[i],B[i]);
        if(i!=N-1) chmax(A[i],A[i+1]);
    }

    vi C(N+1);
    FOR(i,N) C[i+1] = A[i] + C[i];
    vi ans;
    while(Q--){
        INT(L,R);
        L--;
        ans.eb(C[R]-C[L]);
    }
    print(ans);
}

signed main() {
    INT(T);
    FOR(T) {
        solve();
    }
    return 0;
}