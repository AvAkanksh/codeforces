#if defined(__GNUC__)
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#endif

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// --- Submission 1: Types & High-Perf Aliases ---
using ll = long long;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using lld = long double;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define len(x) ll(x.size())

// --- Submission 1: The Powerful FOR Overload ---
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)

// --- Submission 2: Custom Hash (Anti-Hack) ---
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// --- Submission 1: Fast I/O System ---
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
    void wt(char c) { if (por == SZ) flush(); obuf[por++] = c; }
    void wt(const string &s) { for (char c : s) wt(c); }
    template <typename T> void wt(T x) { if (por > SZ - 32) flush(); if (x < 0) { obuf[por++] = '-'; x = -x; } static char buf[32]; int len = 0; do { buf[len++] = (x % 10) | '0'; x /= 10; } while (x); while (len--) obuf[por++] = buf[len]; }
    void print() { wt('\n'); }
    template <class H, class... T> void print(H &&h, T &&...t) { wt(h); if (sizeof...(T)) wt(' '); print(forward<T>(t)...); }
    void __attribute__((destructor)) _d() { flush(); }
}

#define INT(...) int __VA_ARGS__; fastio::rd(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; fastio::rd(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); fastio::rd(name)

// --- Submission 2: Full Debugger System ---
#ifdef LOCAL
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map<T, V, custom_hash> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

// --- Main Logic ---
void solve() {
    INT(n);
    VEC(int, a, n);
    debug(a); // This works only on your local machine
    
    int sum = 0;
    FOR(i, n) sum += a[i];
    fastio::print(sum);
}

int main() {
    INT(t);
    FOR(t) solve();
    return 0;
}