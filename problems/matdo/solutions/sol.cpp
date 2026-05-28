#include <bits/stdc++.h>
using namespace std;
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

const int N = 1e7 + 6;
int FT[N];
void init(void) {

    return;
}
void addFT(int i, int val) {
    if(i < 1) return;
    while(i < N) FT[i] += val, i += i & -i;
}
int getFT(int i) {
    int s = 0; while(i) s += FT[i], i -= i & -i;
    return s;
}
void process(void){
    int n, k;
    cin >> n >> k;
    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        addFT(a, 1); addFT(b + 1, -1);
    }
    FOR(i, 1, k) {
        int x; cin >> x;
        cout << getFT(x) << '\n';
    }
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
    