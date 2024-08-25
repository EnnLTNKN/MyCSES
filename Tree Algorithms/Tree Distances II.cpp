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
#define int ll
pii H[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const int maxn = 2e5 + 4, maxm = 32, Mod = 1e9 + 7;
 
int f[maxn], n, ans[maxn];
vector<int> a[maxn];
void Solve(){
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    function<void(int, int, int)> dfs_1 = [&](int u, int pu, int dist){
        f[u] = 1; 
        ans[1] += dist;
        for (auto v: a[u]) if (v != pu){
            dfs_1(v, u, dist + 1);
            f[u] += f[v];
        }
    };
 
    dfs_1(1, 0, 0);
 
    function<void(int, int)> dfs_2 = [&](int u, int pu){
        for (auto v: a[u]) if (v != pu){
            ans[v] = ans[u] + n - 2 * f[v];
            dfs_2(v, u);
        }
    };
 
    dfs_2(1, 0);
    FOR(i, 1, n) cout << ans[i] << " ";
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