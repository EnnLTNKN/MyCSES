#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 5e3 + 1;
struct fenwick{
    int n; vector<int> f;
    fenwick(int n){
        this -> n = n;
        f.resize(n + 1);
    }
 
    void add(int i, int x){
        for (; i <= n; i += i & -i) f[i] = max(f[i], x);
    }
 
    int get(int i){
        int mx = 0;
        for (; i; i -= i & -i) mx = max(mx, f[i]);
        return mx;
    }
};
 
struct item{
    int l, r, paid;
    item(){}
    bool operator < (item b){
        return this -> r < b.r;
    }
};
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<item> a(n);
    vector<int> c;
    for (auto &x: a){
        cin >> x.l >> x.r >> x.paid;
        c.push_back(x.l); c.push_back(x.r);
    }
 
    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    sort(a.begin(), a.end());
 
    fenwick bit(c.size());
    int ans = 0;
    for (auto [l, r, paid]: a){
        l = lower_bound(c.begin(), c.end(), l) - c.begin() + 1;
        r = lower_bound(c.begin(), c.end(), r) - c.begin() + 1;
        int cur = bit.get(l - 1) + paid;
        bit.add(r, cur);
        ans = max(ans, cur);
    }
 
    cout << ans;
}