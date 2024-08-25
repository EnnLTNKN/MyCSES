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
int n, c[maxn], st[maxn], ed[maxn], m = 0, cnt[maxn], curans = 0, siz[maxn], atPos[maxn], res[maxn];
vector<int> a[maxn], b;
 
void dfs(int u, int pu){
    st[u] = ++ m; atPos[m] = u; siz[u] = 1;
    for (int v: a[u]) if (v != pu) {
        dfs(v, u);
        siz[u] += siz[v];
    }
    ed[u] = m;
}
void add(int x){
    if (cnt[x] == 0) curans ++;
    cnt[x] ++;
}
 
void eli(int x){
    cnt[x] --;
    if (cnt[x] == 0) curans --;
}
 
void sack(int u, int pu, bool IsHeavy){
    int bestsiz = 0, heavy = 0;
    for (int v: a[u]) if (v != pu && bestsiz <= siz[v])
        bestsiz = siz[v], heavy = v;
    for (int v: a[u]) if (v != pu && v != heavy) sack(v, u, 0);
    if (heavy) sack(heavy, u, 1);
 
    add(c[u]);
    for (int v: a[u]) if (v != pu && v != heavy){
        for (int i = st[v]; i <= ed[v]; i ++) add(c[atPos[i]]);
    }
 
    res[u] = curans;
 
    if (!IsHeavy){
        for (int i = st[u]; i <= ed[u]; i ++) eli(c[atPos[i]]);
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n;
 
    FOR(i, 1, n) cin >> c[i], b.push_back(c[i]);
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    sort(All(b)); b.resize(unique(All(b)) - b.begin());
    FOR(i, 1, n) c[i] = lower_bound(All(b), c[i]) - b.begin() + 1;
 
    dfs(1, 0);
    sack(1, 0, 0);
 
    FOR(i, 1, n) cout << res[i] << " ";
 
}