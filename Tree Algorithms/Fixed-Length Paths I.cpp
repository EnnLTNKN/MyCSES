#include<bits/stdc++.h>
using namespace std;
#define el cout << "\n";
#define ll long long
//#define int ll
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
 
#define maxn 200001
int n, siz[maxn], k;
bool Del[maxn];
vector<int> a[maxn];
int dfs(int u, int pu = 0){
    siz[u] = 1;
    for (int i: a[u]) if (!Del[i] && i != pu)
        siz[u] += dfs(i, u);
    return siz[u];
}
 
int Find(int u, int pu, int curn){
    for (int v: a[u]) if (v != pu && siz[v] >= curn && !Del[v])
        return Find(v, u, curn);
    return u;
}
 
ll cnt[maxn], ans = 0, mx = 0;
void getFromroot(int u, int pu, bool Cal, int curDist = 1){
    if (curDist > k) return;
    maximize(mx, curDist);
 
    if (Cal) ans += cnt[k - curDist];
    else cnt[curDist] ++;
 
    for (int v: a[u]) if (v != pu && !Del[v]) getFromroot(v, u, Cal, curDist + 1);
}
 
void centroid(int u){
    int root = Find(u, -1, dfs(u) >> 1);
    Del[root] = 1;
    mx = 0;
 
    cnt[0] = 1;
    for (int v: a[root]) if (!Del[v]) {
        getFromroot(v, root, 1);
        getFromroot(v, root, 0);
    }
 
    fill(cnt + 1, cnt + mx + 1, 0);
 
    for (int v: a[root]) if (!Del[v]) centroid(v);
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> k;
    FOR(i, 1, n - 1){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    centroid(1);
    cout << ans;
}
