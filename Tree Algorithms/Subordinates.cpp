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
int res[maxn], n;
 
void dfs(int u, int pu){
    res[u] = 1;
    for (int v: a[u]) if (v != pu) dfs(v, u), res[u] += res[v];
}
void solve(){
    cin >> n;
    FOR(i, 2, n){
        int x; cin >> x;
        a[x].push_back(i);
    }
 
    dfs(1, 0);
    FOR(i, 1, n) cout << res[i] - 1 << " ";
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