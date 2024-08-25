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
int n, f[maxn][19], h[maxn], q;
vector<int> a[maxn];
 
void dfs(int u){
    for (int v: a[u]) if (v != f[u][0]){
        f[v][0] = u;
        h[v] = h[u] + 1;
        FOR(i, 1, 18) f[v][i] = f[f[v][i - 1]][i - 1];
        dfs(v);
    }
}
 
int get(int u, int dist){
    if (dist > h[u]) return -1;
    FOR(i, 0, 18) if (dist >> i & 1) u = f[u][i];
    return u;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
    // FILE
 
    cin >> n >> q; FOR(i, 2, n){
        int x; cin >> x;
        a[x].push_back(i);
    }
    
    dfs(1);
    while (q --){
        int u, h; cin >> u >> h;
        cout << get(u, h) << "\n";
    }
}