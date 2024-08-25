#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= (int) b; i ++)
#define FORD(i, a, b) for (int i = a; i >= (int) b; i --)
#define ll long long
#define pii pair<ll, ll>
#define PB push_back
#define FBit 31 - __builtin_clz(n)
#define All(a) a.begin(), a.end()
#define Eb emplace_back
#define X first
#define Y second
#define int long long
#define TENBAI "XEPBI"
#define NAME "Enn"
#define Size(n) (int) n.size()
#define SetPrecision(i) cout << fixed << setprecision(i)
#define Bts(i) bitset<i>
#define Prque(a) priority_queue<int> a
#define el cout << "\n"
#define CntBit(a) __builtin_popcount(a)
#define CheckBit(i, mask) (mask >> (i - 1) & 1)
#define BitOn(i, mask) mask | (1 << (i - 1))
#define BitOff(i, mask) mask & (~(1 << (i - 1)))
using namespace std;
constexpr int MN = 1e6 + 2, Mod = 1e9 + 7, base = 31;
constexpr int MaxAi = 1e6 + 2;
pii H[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 
/// Haven't Name -------------------------------------------
/// ------------------------------------------- Haven't Name
 
int Ft[MN + 2], InvFt[MN + 2];
int Pow(int a, int b){
    int ans = 1;
    for (; b > 0; b /= 2){
        if (b % 2) (ans *= a) %= Mod;
        a = (a * a) % Mod;
    }
 
    return ans;
}
 
vector<vector<int>> C[5];
void Pre_Comb(){
    Ft[1] = 1;
    FOR(i, 2, MN) Ft[i] = Ft[i - 1] * i % Mod;
    InvFt[MN] = Pow(Ft[MN], Mod - 2);
    FORD(i, MN, 1) InvFt[i - 1] = InvFt[i] * i % Mod;
}
 
int Comb(int k, int n){
    if (k > n) return 0;
    return Ft[n] * InvFt[k] % Mod * InvFt[n - k] % Mod;
}
 
/// ------------------------------------------- Haven't Name
/// Haven't Name -------------------------------------------
 
int f1[MN], f2[MN];
vector<int> a[MN];
void Dfs(int u, int pu){
    vector<int> cur;
    for (int v: a[u]){
        if (v != pu){
            Dfs(v, u);
            cur.push_back(f1[v]);
        }
    }
 
    if (Size(cur) == 0){
        f1[u] = 1;
    }
 
    else {
        sort(All(cur), greater<int> ());
        f1[u] = cur[0] + 1;
        if (Size(cur) > 1){
            f2[u] = cur[0] + cur[1] + 1;
        }
    }
}
void Solve(){
 
    int n; cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    Dfs(1, -1);
 
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max({ans, f1[i], f2[i]});
    }
 
    cout << ans - 1;
}
 
 
/// ------------------------------------------- Haven't Name
/// Haven't Name -------------------------------------------
 
int32_t main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Pre_Comb();
 
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);
    ///-------------------------------///
//    freopen(TENBAI".inp", "r", stdin);
//    freopen(TENBAI".out", "w", stdout);
 
    int t = 1;
//    cin >> t ;
 
    while (t --) {
        Solve();
        cout << "\n";
    }
}