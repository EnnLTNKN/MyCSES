/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define fi first
#define se second
int Hx[] = {};
int Hy[] = {};
const int mod = 1e9 + 7, inf = 1e18;
template<class A, class B> bool maximize(A &a, B b) { return a < b && (a = b, true); }
template<class A, class B> bool minimize(A &a, B b) { return a > b && (a = b, true); }
 
const int maxn = 2e5 + 1;
int f[maxn];
 
void add(int x, int val){
    for (; x <= maxn - 1; x += x & -x) f[x] += val;
}
 
int get(int x){
    int sum = 0;
    for (; x; x -= x & -x) sum += f[x];
    return sum;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, q; cin >> n >> q;
    vector<int> a(n + 1); FOR(i, 1, n) cin >> a[i];
    vector<vector<pii>> qr(n + 1);
 
    map<int, int> mp;
    FOR(i, 1, q){
        int l, r; cin >> l >> r;
        qr[r].push_back(pii(l, i));
    }
 
    vector<int> ans(q + 1);
    FOR(i, 1, n){
        if (mp[a[i]]) add(mp[a[i]], -1);
        mp[a[i]] = i; add(mp[a[i]], 1);
        for (auto [l, id]: qr[i]){
            ans[id] = get(i) - get(l - 1);
        }
    }
    
    FOR(i, 1, q) cout << ans[i] << "\n";
}