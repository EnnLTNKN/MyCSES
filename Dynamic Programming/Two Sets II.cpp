#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7;
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    if (n * (n + 1) / 2 % 2) return cout << 0, 0;
 
    vector<int> f(n * (n + 1) / 2 + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = n * (n + 1) / 4; j >= i; j --) (f[j] += f[j - i]) %= mod;
 
    int ans = f[n * (n + 1) / 4];
    if (ans % 2 == 0) cout << ans / 2 << "\n";
    else cout << ((ans + mod) / 2) % mod;
}