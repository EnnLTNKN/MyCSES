#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i ++) 
#define FORD(i, a, b) for (int i = a; i >= b; i --)
#define el cout << "\n";
#define pii pair<int, int>
#define X first
#define Y second
#define ll int64_t
#define inf 1e9
pii H[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const int maxn = 2e5 + 4, maxm = 32, Mod = 1e9 + 7;
 
int n, m, p[maxn], k, c[maxn];
vector<int> a[maxn];
struct node{
    int _1st, _2nd;
    node(){
        _1st = _2nd = -inf;
    }
 
    void getmax(int x){
        if (x >= _1st){
            _2nd = _1st;
            _1st = x;
        }
 
        else _2nd = max(_2nd, x);
    }
 
    void operator = (node a){
        _1st = a._1st;
        _2nd = a._2nd;
    }
 
} f[maxn];
 
void Solve(){
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    function<void(int, int)> _dfs1 = [&](int u, int pu){
        f[u].getmax(0);
        for (int v: a[u]) if (v != pu){
            _dfs1(v, u);
            if (f[u]._1st <= f[v]._1st + 1){
                c[u] = v;
            }
 
            f[u].getmax(f[v]._1st + 1);
        }
    };
 
    function<void(int, int)> _dfs2 = [&](int u, int pu){
        for (int v: a[u]) if (v != pu){
            if (c[u] == v){
                if (f[v]._1st < f[u]._2nd + 1) c[v] = u; 
                f[v].getmax(f[u]._2nd + 1);
            }
 
            else {
                f[v].getmax(f[u]._1st + 1);
                c[v] = u;
            }
 
            _dfs2(v, u);
        }
    };
 
    _dfs1(1, 0);
    _dfs2(1, 0);
    FOR(i, 1, n) cout << f[i]._1st << " ";
}
 
int nTest = 1;  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // #define name "enn"
    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);
 
    // cin >> nTest;
    while (nTest --) {
        Solve();
        el;
    }
}