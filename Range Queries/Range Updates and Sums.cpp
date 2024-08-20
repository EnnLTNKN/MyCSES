/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
const int maxn = 2e5 + 1;
int n, q, a[maxn], sum[maxn * 4], add[maxn * 4], ass[maxn * 4];
 
void build(int i, int l, int r){
    if (l == r) return void(sum[i] = a[l]);
    int mid = (l + r) >> 1;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}
 
void Add(int i, int l, int r, int val){
    sum[i] += val * (r - l + 1);
    add[i] += val;
}
 
void Ass(int i, int l, int r, int val){
    sum[i] = val * (r - l + 1);
    ass[i] = val;
    add[i] = 0;
}
 
void down(int i, int l, int r){
    int mid = (l + r) >> 1;
    if (ass[i]){
        Ass(i * 2, l, mid, ass[i]);
        Ass(i * 2 + 1, mid + 1, r, ass[i]);
        ass[i] = 0;
    }
 
    Add(i * 2, l, mid, add[i]);
    Add(i * 2 + 1, mid + 1, r, add[i]);
    add[i] = 0;
}
 
void update(int i, int l, int r, int u, int v, int val, int t){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        if (!t) Add(i, l, r, val);
        else Ass(i, l, r, val);
        return;
    }
 
    down(i, l, r);
    int mid = (l + r) >> 1;
    update(i * 2, l, mid, u, v, val, t);
    update(i * 2 + 1, mid + 1, r, u, v, val, t);
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}
 
int get(int i, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return sum[i];
 
    down(i, l, r);
    int mid = (l + r) >> 1;
    return get(i * 2, l, mid, u, v) + get(i * 2 + 1, mid + 1, r, u, v);
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
 
    build(1, 1, n);
    while (q --){
        int t; cin >> t;
        if (t == 1){
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x, 0);
        }
 
        else if (t == 2){
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x, 1);
        }
 
        else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
}