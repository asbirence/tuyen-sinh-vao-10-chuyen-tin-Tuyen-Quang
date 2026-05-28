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

void init(void) {

    return;
}

int dp[20][2][11][11];
int x[17];
int f(int id, bool smaller, int u, int v) {
    if(id < 0) return u < v && u != 10 && v != 10;
    int &res = dp[id][smaller][u][v];
    if(res != -1) return res; res = 0;
    int limit = (smaller ? 9 : x[id]);
    FOR(i, 0, limit) {
        res += f(id - 1, smaller || (i < limit), (id == 1) ? i : u, (id == 0) ? i : v);
    }
    return res;
}
int cnt(int v){
    if (v < 0) return 0;
    int n = 0;
    for(int i = 0; i <= 18; i++) {
        x[n++] = v % 10;
        v /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return f(n - 1, 0, 10, 10);
}
void process(void){
    int a, b;
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1) << '\n';
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
    