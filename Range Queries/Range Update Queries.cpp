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
    int n; vector<int> lazy;
    segtree(int n){
        this -> n = n;
        lazy.resize(4 * n + 1);
    }
 
    void down(int i){
        for (int j = i * 2; j <= i * 2 + 1; j ++) lazy[j] += lazy[i];
        lazy[i] = 0;
    }
 
    void update(int i, int l, int r, int u, int v, int val){
        if (l > v || r < u) return;
        if (u <= l && r <= v){
            lazy[i] += val;
            return;
        }
 
        down(i);
        int mid = (l + r) >> 1;
        update(i * 2, l, mid, u, v, val);
        update(i * 2 + 1, mid + 1, r, u, v, val);
    }
    
    int get(int pos){
        int i = 1, l = 1, r = n;
        while (l < r){
            int mid = (l + r) >> 1;
            down(i);
            if (mid < pos) l = mid + 1, i = i * 2 + 1;
            else r = mid, i = i * 2;
        }
 
        return lazy[i];
    }
    
};
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1); for (int i = 1; i <= n; i ++) cin >> a[i];
 
    segtree f(n);
    while (q --){
        int t; cin >> t;
        if (t == 1){
            int l, r, val; cin >> l >> r >> val;
            f.update(1, 1, n, l, r, val);
        }
 
        else{
            int pos; cin >> pos;
            cout << a[pos] + f.get(pos) << "\n";
        }
    }
}