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
 
int f[sizSegment(maxn) + 1];
void Set(int pos, int val){
    int i = 1, l = 1, r = n;
    while (l < r){
        int mid = (l + r) >> 1;
        if (pos <= mid) r = mid, i = i * 2;
        else l = mid + 1, i = i * 2 + 1;
    }
 
    f[i] = val;
    while (i > 1){
        i >>= 1;
        f[i] = f[i * 2] + f[i * 2 + 1];
    }
}
 
int get(int i, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return f[i];
    int mid = (l + r) >> 1;
    int Left = get(i * 2, l, mid, u, v);
    int Right = get(i * 2 + 1, mid + 1, r, u, v);
 
    return Left + Right;
}
 
int query(int u){
    int sum = 0;
    for (; u ; u = par[head[u]]){
        sum += get(1, 1, n, inArray[head[u]], inArray[u]);
    }
 
    return sum;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
    // FILE
 
    cin >> n >> q;
 
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dfs(1, 0);
    hld(1, 1);
 
    FOR(i, 1, n) Set(inArray[i], c[i]);
 
    while (q --){
        int tp, s; cin >> tp >> s;
        if (tp == 1){
            int x; cin >> x;
            Set(inArray[s], x);
        }
        else cout << query(s) << "\n";
    }
 
}