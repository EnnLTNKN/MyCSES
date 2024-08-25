#include<bits/stdc++.h>
using namespace std;
#define el cout << "\n";
#define ll long long
// #define int ll
#define pii pair<int, int>
#define All(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define FORD(i, a, b) for (int i = a; i >= b; i --)
#define sizSegment(n) (1 << (31 - __builtin_clz(n) + 2))
#define FILE freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
pii H[] = {{-1, 0}, {0, -1}};
const int mod = 1e9 + 22071997, inf = 1e18;
template<class A, class B> bool maximize(A &a, const B &b) { return a < b && (a = b, true); }
template<class A, class B> bool minimize(A &a, const B &b) { return a > b && (a = b, true); }
template<class A, class B> void add(A &a, const B &b) { a += b; if (a >= mod) a -= mod; }
template<class A, class B> void sub(A &a, const B &b) { a -= b; if (a < 0) a += mod; }
 
#define maxn 200100
vector<int> a[maxn];
int par[maxn], head[maxn], siz[maxn], heavy[maxn], h[maxn], c[maxn];
int n, q;
 
void dfs(int u, int pu){
    siz[u] = 1;
    int bestSiz = 0;
    for (int v: a[u]) if (v != pu){
        par[v] = u;
        h[v] = h[u] + 1;
 
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v]  > bestSiz) bestSiz = siz[v], heavy[u] = v;
    }
}
 
int inArray[maxn], cnt = 0, b[maxn];
void hld(int u, int h){
    head[u] = h; inArray[u] = ++ cnt, b[cnt] = c[u];
    if (heavy[u] != 0) hld(heavy[u], h);
    for (int v: a[u]) if (v != par[u] && v != heavy[u]) hld(v, v);
}
 
int f[4 * maxn + 1];
void Set(int p, int val){
    for (f[p += n] = val; p > 1; p >>= 1) f[p >> 1] = max(f[p], f[p ^ 1]);
}
 
int get(int l, int r){
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l & 1) maximize(res, f[l ++]);
        if (r & 1) maximize(res, f[-- r]);
    }
 
    return res;
}
 
int query(int u, int v){
    int mx = 0;
    for (; head[u] != head[v]; v = par[head[v]]){
        if (h[head[u]] > h[head[v]]) swap(u, v);
        maximize(mx, get(inArray[head[v]] - 1, inArray[v]));
    }
 
    if (h[u] > h[v]) swap(u, v);
    maximize(mx, get(inArray[u] - 1, inArray[v]));
 
    return mx;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> q;
 
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dfs(1, 0);
    hld(1, 1);
 
    FOR(i, 1, n) Set(inArray[i] - 1, c[i]);
 
    while (q --){
        int tp, s, x; cin >> tp >> s >> x;
        if (tp == 1){
            Set(inArray[s] - 1, x);
        }
        else cout << query(s, x) << " ";
    }
 
}