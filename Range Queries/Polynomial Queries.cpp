/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int maxn = 2e5 + 1;
int n, q, a[maxn];
 
int getsum(int l, int r){
    return r * (r + 1) / 2 - l * (l - 1) / 2;
}
 
struct segtree1{
    int n; vector<int> sum, lazy;
    segtree1(int n){
        this -> n = n;
        sum.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
 
    void down(int i, int l, int r){
        int mid = (l + r) >> 1;
        lazy[i * 2] += lazy[i]; lazy[i * 2 + 1] += lazy[i];
        sum[i * 2] += lazy[i] * getsum(l, mid); sum[i * 2 + 1] += lazy[i] * getsum(mid + 1, r);
        lazy[i] = 0;
    }
 
    void update(int i, int l, int r, int u, int v){
        if (l > v || r < u) return;
        if (u <= l && r <= v){
            sum[i] += getsum(l, r);
            lazy[i] ++;
            return;
        }
 
        down(i, l, r);
        int mid = (l + r) >> 1;
        update(i * 2, l, mid, u, v);
        update(i * 2 + 1, mid + 1, r, u, v);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
 
    int get(int i, int l, int r, int u, int v){
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return sum[i];
        down(i, l, r);
        int mid = (l + r) >> 1;
        return get(i * 2, l, mid, u, v) + get(i * 2 + 1, mid + 1, r, u, v);
    }
};
 
struct segtree2{
    int n; vector<int> sum, lazy;
    segtree2(int n){
        this -> n = n;
        sum.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
 
    void down(int i, int l, int r){
        int mid = (l + r) >> 1;
        lazy[i * 2] += lazy[i]; lazy[i * 2 + 1] += lazy[i];
        sum[i * 2] += (mid - l + 1) * lazy[i];
        sum[i * 2 + 1] += (r - mid) * lazy[i];
        lazy[i] = 0;
    }
 
    void update(int i, int l, int r, int u, int v, int val){
        if (l > v || r < u) return;
        if (u <= l && r <= v){
            sum[i] += val * (r - l + 1);
            lazy[i] += val;
            return;
        }
 
        down(i, l, r);
        int mid = (l + r) >> 1;
        update(i * 2, l, mid, u, v, val);
        update(i * 2 + 1, mid + 1, r, u, v, val);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
 
    int get(int i, int l, int r, int u, int v){
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return sum[i];
        down(i, l, r);
        int mid = (l + r) >> 1;
        return get(i * 2, l, mid, u, v) + get(i * 2 + 1, mid + 1, r, u, v);
    }
};
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q; for (int i = 1; i <= n; i ++) cin >> a[i];
    segtree1 st1(n); 
    segtree2 st2(n);
 
    for (int i = 1; i <= n; i ++) st2.update(1, 1, n, i, i, a[i]);
 
    while (q --){
        int t, l, r; cin >> t >> l >> r;
        if (t == 1){
            st2.update(1, 1, n, l, r, - l + 1);
            st1.update(1, 1, n, l, r);
        }
 
        else {
            cout << st2.get(1, 1, n, l, r) + st1.get(1, 1, n, l, r) << "\n";
        }
    }
    
}