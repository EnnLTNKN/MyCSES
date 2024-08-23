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
int res[maxn][2], n;
 
void dfs(int u, int pu){
    for (auto v: a[u]) if (v != pu) {
        dfs(v, u);
        res[u][0] += max(res[v][0], res[v][1]);
    }
 
    for (auto v: a[u]) if (v != pu){
        maximize(res[u][1], res[u][0] - max(res[v][0], res[v][1]) + res[v][0] + 1);
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
    int ans = 0;
    FOR(i, 1, n) maximize(ans, max(res[i][0], res[i][1]));
    cout << ans;
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