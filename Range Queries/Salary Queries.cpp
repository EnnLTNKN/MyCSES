#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
// #define int ll
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
int n, q, p[maxn];
vector<int> c;
struct item{
    char t; 
    int x, y;
    item(){}
};
 
item a[maxn];
struct segtree{
    int n; vector<int> f;
    segtree(int n){
        this -> n = n; f.resize(4 * n + 1);
    }
 
    void update(int i, int l, int r, int pos, int val){
        if (l > pos || r < pos) return;
        if (l == r) return void(f[i] += val);
        int mid = (l + r) >> 1;
        update(i * 2, l, mid, pos, val);
        update(i * 2 + 1, mid + 1, r, pos, val);
        f[i] = f[i * 2] + f[i * 2 + 1];
    }
 
    int get(int i, int l, int r, int u, int v){
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return f[i];
        int mid = (l + r) >> 1;
        return get(i * 2, l, mid, u, v) + get(i * 2 + 1, mid + 1, r, u, v);
    }
 
    void update(int pos, int val){
        update(1, 1, n, pos, val);
    }
 
    int get(int l, int r){
        return get(1, 1, n, l, r);
    }
};
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> q; FOR(i, 1, n) cin >> p[i], c.push_back(p[i]);
    FOR(i, 1, q) {
        cin >> a[i].t >> a[i].x >> a[i].y;
        if (a[i].t == '!') c.push_back(a[i].y);
        else c.push_back(a[i].x), c.push_back(a[i].y);
    }
 
    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    segtree f(c.size());
    FOR(i, 1, n) p[i] = lower_bound(c.begin(), c.end(), p[i]) - c.begin() + 1, f.update(p[i], 1);
    FOR(i, 1, q){
        if (a[i].t == '!'){
            a[i].y = lower_bound(c.begin(), c.end(), a[i].y) - c.begin() + 1;
            f.update(a[i].y, 1); f.update(p[a[i].x], -1);
            p[a[i].x] = a[i].y;
        }
        else {
            a[i].x = lower_bound(c.begin(), c.end(), a[i].x) - c.begin() + 1;
            a[i].y = lower_bound(c.begin(), c.end(), a[i].y) - c.begin() + 1;
            cout << f.get(a[i].x, a[i].y) << "\n";
        }
    }
 
 
}