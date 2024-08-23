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
int f[maxn], siz[maxn], n;

void dfs(int u, int pu){
    siz[u] = 1;
    for (auto v: a[u]) if (v != pu) {
        dfs(v, u);
        siz[u] += siz[v];
        f[u] += f[v] + siz[v];
    }
}

void dfs2(int u, int pu){
    for (auto v: a[u]) if (v != pu){
        f[v] = f[u] - f[v] - siz[v] + (n - siz[v]) + f[v];
        dfs2(v, u);
    }
}

void solve(){
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);
    dfs2(1, 0);

    FOR(i, 1, n) cout << f[i] << " ";
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