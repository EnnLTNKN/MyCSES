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
int f1[maxn], f2[maxn];

void dfs(int u, int pu, int f[]){
    for (int v: a[u]) if (v != pu) f[v] = f[u] + 1, dfs(v, u, f);
}

void solve(){
    int n; cin >> n;

    if (n == 1) return void(cout << 0);
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0, f1);
    int mx = 0, st; FOR(i, 1, n) if (maximize(mx, f1[i])) st = i;
    dfs(st, 0, f2);
    mx = 0;
    FOR(i, 1, n) maximize(mx, f2[i]);
    cout << mx;
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