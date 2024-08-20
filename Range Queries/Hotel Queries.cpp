#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define All(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define FORD(i, a, b) for (int i = a; i >= b; i --)
#define FILE freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define fi first
#define se second
int Hx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int Hy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int mod = 1e9 + 7, inf = 1e18;
template<class A, class B> bool maximize(A &a, B b) { return a < b && (a = b, true); }
template<class A, class B> bool minimize(A &a, B b) { return a > b && (a = b, true); }
/*                                          ᴷᴺ✞ঔৣ۝NoNameCoder                                               */
 
const int maxn = 2e5 + 1;
int n, m, h[maxn];
pii f[maxn * 4];
 
int Jump(int i, int l, int r, int val){
    if (f[i].first < val) return 0;
    if (l == r) return f[i].second;
 
    int mid = (l + r) >> 1;
    if (f[i * 2].first >= val) return Jump(i * 2, l, mid, val);
    return Jump(i * 2 + 1, mid + 1, r, val);
}
 
void Update(int i, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r) return void(f[i] = pii(f[i].first + val, pos));
    int mid = (l + r) >> 1;
    Update(i * 2, l, mid, pos, val);
    Update(i * 2 + 1, mid + 1, r, pos, val);
    f[i] = max(f[i * 2], f[i * 2 + 1]);
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> m;
    FOR(i, 1, n) cin >> h[i], Update(1, 1, n, i, h[i]);
    while (m --){
        int x; cin >> x;
        int ans = Jump(1, 1, n, x);
        cout << ans << " ";
 
        if (ans != 0) Update(1, 1, n, ans, -x);
    }
 
}