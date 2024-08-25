#include<bits/stdc++.h>
using namespace std;
#define el cout << "\n";
#define ll long long
#define int ll
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
int n, m;
int p[maxn][19], h[maxn], s[maxn], f[maxn];
vector<int> a[maxn];
void dfs(int u){
    for (int v: a[u]) if (v != p[u][0]){
        p[v][0] = u;
        h[v] = h[u] + 1;
        FOR(i, 1, 18) p[v][i] = p[p[v][i - 1]][i - 1];
        dfs(v);
    }
}
 
int lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int dist = h[u] - h[v];
    FOR(i, 0, 18) if (dist >> i & 1) u = p[u][i];
    if (u == v) return u;
 
    FORD(i, 18, 0) if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
    return p[u][0];
}
 
void Up(int u, int pu){
    for (int v: a[u]) if (v != pu){
       Up(v, u); s[u] += s[v];
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
    // FILE
 
    int n, m; 
    cin >> n >> m; FOR(i, 2, n){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    p[1][0] = 0;
    dfs(1);
    memset(s, 0, sizeof s);
 
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        if (h[u] < h[v]) swap(u, v);    
        int tmp = lca(u, v);
 
        if (u == v) s[u] ++, s[p[u][0]] --;
        else if (v == tmp) s[u] ++, s[p[v][0]] --;
        else s[u] ++, s[v] ++, s[tmp] --, s[p[tmp][0]] --;
    }
 
    Up(1, 0);
    FOR(i, 1, n) cout << s[i] << " ";
 
}