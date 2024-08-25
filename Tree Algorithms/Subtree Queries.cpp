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
int n, q, c[maxn], f[4 * maxn];
vector<int> a[maxn];
int st[maxn], ed[maxn], atPos[maxn], cnt = 0;
 
void update(int pos, int val){
    int i = 1, l = 1, r = n;
    while (l < r){
        int m = (l + r) >> 1;
        if (pos <= m) r = m, i = i * 2;
        else l = m + 1, i = i * 2 + 1;
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
 
void dfs(int u, int pu){
    st[u] = ++cnt; atPos[cnt] = u;
 
    for (int v: a[u]) if (v != pu) dfs(v, u);
    ed[u] = cnt;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
    // FILE
 
    cin >> n >> q;
 
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 2, n){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dfs(1, 0);
    FOR(i, 1, n) update(st[i], c[i]);
 
    while (q --){
        int tp, s, x; cin >> tp >> s;
        if (tp == 1){
            cin >> x;
            update(st[s], x);
        }
 
        else cout << get(1, 1, n, st[s], ed[s]) << "\n";
    }
    
}