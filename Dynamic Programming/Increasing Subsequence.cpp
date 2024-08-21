#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7;
 
struct fenwick{
    int n; vector<int> f;
    fenwick(int n){
        this -> n = n;
        f.resize(n + 1);
    }
 
    void add(int i, int val){
        for (; i <= n; i += i & -i) f[i] = max(f[i], val);
    }
 
    int get(int i){
        int mx = 0;
        for (; i; i -= i & -i) mx = max(mx, f[i]);
        return mx;
    }
};
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> c = a;
    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
 
    int ans = 1;
    fenwick bit(c.size());
    for (int &x: a){
        x = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
        int cur = bit.get(x - 1) + 1;
        bit.add(x, cur);
 
        ans = max(ans, cur);
    }
 
    cout << ans;
}