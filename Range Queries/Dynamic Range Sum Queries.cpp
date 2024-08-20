#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define pii pair<int, int>
pii H[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7, maxn = 20;
 
struct segtree{
    int n; vector<int> f, a;
    segtree(int n, vector<int> a){
        this -> n = n;
        this -> a = a;
        f.resize(4 * n + 1);
        build(1, 1, n);
    }
 
    void build(int i, int l, int r){
        if (l == r) return void(f[i] = a[l]);
        int mid = (l + r) >> 1;
        build(i * 2, l, mid); build(i * 2 + 1, mid + 1, r);
        f[i] = f[i * 2] + f[i * 2 + 1];
    }
    
    void update(int i, int l, int r, int k, int val){
        if (l > k || r < k) return;
        if (l == r) return void(f[i] = val);
        int mid = (l + r) >> 1;
        update(i * 2, l, mid, k, val);
        update(i * 2 + 1, mid + 1, r, k, val);
        f[i] = f[i * 2] + f[i * 2 + 1];
    }
 
    int get(int i, int l, int r, int u, int v){
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return f[i];
        int mid = (l + r) >> 1;
        return get(i * 2, l, mid, u, v) +get(i * 2 + 1, mid + 1, r, u, v);
    }
};
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), s(n + 1); for (int i = 1; i <= n; i ++) cin >> a[i];
    segtree f(n, a);
    while (q --){
        int t; cin >> t;
        if (t == 2){
            int l, r; cin >> l >> r;
            cout << f.get(1, 1, n, l, r) << "\n";   
        }
        else{
            int k, val; cin >> k >> val;
            f.update(1, 1, n, k, val);
        }
    }
    
}