#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 20;
int f[1 << maxn], remain[1 << maxn];
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto &x: a) cin >> x;
 
    f[0] = 1;
    for (int mask = 1; mask < (1 << n); mask ++){
        int numEle = 1e18, rm = 1e18;
        for (int i = 0; i < n; i ++) {
            if (mask >> i & 1){
                int oldMask = mask ^ (1 << i);
                if (remain[oldMask] + a[i] <= x){
                    if (numEle > f[oldMask]) numEle = f[oldMask], rm = remain[oldMask] + a[i];
                    else if (numEle == f[oldMask]) rm = min(rm, remain[oldMask] + a[i]);
                }
                else {
                    if (numEle > f[oldMask] + 1) numEle = f[oldMask] + 1, rm = a[i];
                    else if (numEle == f[oldMask] + 1) rm = min(rm, a[i]);
                }
            }
        }
 
        f[mask] = numEle; remain[mask] = rm;
    }
 
    cout << f[(1 << n) - 1];
}
