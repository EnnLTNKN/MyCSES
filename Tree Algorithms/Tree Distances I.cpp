#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define FORD(i, a, b) for (int i = a; i >= b; i --)
#define pii pair<int, int>
#define fi first
#define se second
#define all(c) c.begin(), c.end()
#define FILE freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);
template<class A, class B> bool maximize(A &a, B b) {return a < b && (a = b, true);}
template<class A, class B> bool minimize(A &a, B b) {return a > b && (a = b, true);}

const int maxn = 2e5 + 1;
vector<int> a[maxn];
pii f[maxn];

void Set(pii &mx, int x){
    if (mx.fi <= x) mx.se = mx.fi, mx.fi = x;
    else maximize(mx.se, x);
}

void dfs(int u, int pu){
    for (auto v: a[u]) if (v != pu){
        dfs(v, u);
        Set(f[u], f[v].fi + 1);
    }
}

void dfs2(int u, int pu){
    for (auto v: a[u]) if (v != pu){
        if (f[v].fi + 1 == f[u].fi) Set(f[v], f[u].se + 1);
        else Set(f[v], f[u].fi + 1);

        dfs2(v, u);
    }
}

void solve(){
    int n; cin >> n;
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);
    dfs2(1, 0);

    FOR(i, 1, n) cout << f[i].fi << " ";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #define NAME "enn"
    // FILE

    int t = 1;
    // cin >> t;
    while (t --){
        solve();
        cout << "\n";
    }
}