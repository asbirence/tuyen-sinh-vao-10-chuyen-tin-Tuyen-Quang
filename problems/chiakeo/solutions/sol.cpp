#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for(int i = 0, _n = (n); i < _n; i++)
#define inpFile(Task) freopen(Task".inp", "r", stdin)
#define outFile(Task) freopen(Task".out", "w", stdout)
#define file(Task) inpFile(Task); outFile(Task);
#define ALL(x) (x).begin(), (x).end()
#define BIT(n, k) ((n)>>(k)&1)
#define MASK(n) (1ll<<(n))

template<class X, class Y> bool minimize(X &x, const Y &y){
    if(x > y){x = y;return true;}
    return false;
}

template<class X, class Y>bool maximize(X &x, const Y &y){
    if(x < y){ x = y; return true;}
    return false;
}

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long r){
    return uniform_int_distribution<long long>(l, r) (rnd);
}

struct Compress : vector<int> {
    void build(void) { sort(begin(), end()); erase(unique(begin(), end()), end()); }
    int prod(int val) { return lower_bound(begin(), end(), val) - begin() + 1; }
};

int getlog(long long n) { return 63-__builtin_clzll(n); }
bool multitest = false;

inline char gc() {
    static char buf[1 << 17];
    static size_t buf_st, buf_en;
    if (buf_st >= buf_en) buf[0] = 0, buf_st = 0, buf_en = fread(buf, 1, sizeof(buf), stdin);
    return buf[buf_st++];
}
inline char rch() {
    char c; while ((c = gc()) < 33);
    return c;
}
inline string rstr() {
    string s; char c;
    while ((c = gc()) < 33);
    for (s += c; (c = gc()) >= 33; s += c);
    return s;
}
inline int rint() {
    int x; char c;
    while ((c = gc()) < 45); if (c == 45) return -rint();
    for (x = c- 48; (c = gc()) >= 48; x = x * 10 + c - 48);
    return x;
}
void init(void) {

    return;
}
const int N  = 1e6 + 5;
int cnt[N];
void process(void){
    int res = 0;
    int n = rint(), k = rint();
    FOR(i, 1, n) {
        int v = rint(); v %= k;
        res += cnt[(k - v) % k]; cnt[v]++;
    };
    cout << res << '\n';
    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef HEHE
    if(fopen("input.txt", "r")){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    #endif
    init();
    int numTest; if(multitest) cin >> numTest; else numTest = 1;
    while(numTest--) process();
    #ifdef HEHE
    cerr << "Time elapsed: " << 1.000 * clock() / CLOCKS_PER_SEC << " ms\n";
    #endif
    return 0;
}
    