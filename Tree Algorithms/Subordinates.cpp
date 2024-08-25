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
int n, f[maxn];
 
void dfs(int u, int pu){
    f[u] = 1;
    for (int v: a[u]) if (v != pu){
        dfs(v, u);
        f[u] += f[v];
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
    // FILE
 
    cin >> n; FOR(i, 2, n){
        int x; cin >> x;
        a[x].push_back(i);
    }
 
    dfs(1, 0);
    FOR(i, 1, n) cout << f[i] - 1 << " ";
}