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
int n, q, a[maxn];
 
struct item{
    int pre, sum;
    item(){}
    item(int pre, int sum){ this -> pre = pre; this -> sum = sum; }
} f[maxn * 4];
 
item operator + (item a, item b){
    item c; c.sum = a.sum + b.sum;
    c.pre = max({a.sum + b.pre, a.pre, 0ll});
    return c;
}
 
void update(int i, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r) return void(f[i] = item(max(0ll, val), val));
    int mid = (l + r) >> 1;
    update(i * 2, l, mid, pos, val);
    update(i * 2 + 1, mid + 1, r, pos, val);
    f[i] = f[i * 2] + f[i * 2 + 1];
}
 
item get(int i, int l, int r, int u, int v){
    if (l > v || r < u) return item(0, 0);
    if (u <= l && r <= v) return f[i];
    int mid = (l + r) >> 1;
    return get(i * 2, l, mid, u, v) + get(i * 2 + 1, mid + 1, r, u, v); 
}
 
void show(int i, int l, int r){
    if (l == r) return;
    int mid = (l + r) >> 1;
    show(i * 2, l, mid);
    show(i * 2 + 1, mid + 1, r);
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i], update(1, 1, n, i, a[i]);
    while (q --){
        int t; cin >> t;
        if (t == 1){
            int k, val; cin >> k >> val;
            update(1, 1, n, k, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r).pre << "\n";
        }
    }
}