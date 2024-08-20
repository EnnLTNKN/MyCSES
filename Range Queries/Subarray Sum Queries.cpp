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
#define FILE freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define fi first
#define se second
int Hx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int Hy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int mod = 1e9 + 7, inf = 1e18;
template<class A, class B> bool maximize(A &a, B b) { return a < b && (a = b, true); }
template<class A, class B> bool minimize(A &a, B b) { return a > b && (a = b, true); }
 
const int maxn = 2e5 + 1;
int n, q;
struct item{
    int pre, suf, sum, best;
    item(){}
    item(int pre, int suf, int sum, int best){
        this -> pre = pre, this -> suf = suf, this -> sum = sum, this -> best = best;
    }
} f[maxn * 4];
 
item operator + (item a, item b){
    item c;
    c.sum = a.sum + b.sum;
    c.pre = max(a.sum + b.pre, a.pre);
    c.suf = max(a.suf + b.sum, b.suf);
    c.best = max({a.best, b.best, a.suf + b.pre});
    return c;
}
 
void update(int i, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r) return void(f[i] = item(max(0ll, val), max(0ll, val), val, max(0ll, val)));
    int mid = (l + r) >> 1;
    update(i * 2, l, mid, pos, val);
    update(i * 2 + 1, mid + 1, r, pos, val);
    f[i] = f[i * 2] + f[i * 2 + 1];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
    cin >> n >> q;
    FOR(i, 1, n){
        int x; cin >> x;
        update(1, 1, n, i, x);
    }
 
    while (q --){
        int i, val; cin >> i >> val;
        update(1, 1, n, i, val);
        cout << f[1].best << "\n";
    }
}