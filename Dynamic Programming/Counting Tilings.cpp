#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 20;
 
int f[2][11][1 << (12)];
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> m >> n;
    f[0][m][0] = 1;
    for (int i = 1; i <= n; i ++){
        memset(f[1], 0, sizeof f[1]);
        for (int mask = 0; mask < (1 << (m + 1)); mask ++) f[1][0][mask << 1] = f[0][m][mask];
        for (int j = 1; j <= m; j ++){
            for (int mask = 0; mask < (1 << (m + 1)); mask ++){
                int t1 = mask >> j & 1;
                int t2 = mask >> (j - 1) & 1;
                if (t1 && !t2) (f[1][j][mask] += f[1][j - 1][mask ^ (1 << j)]) %= mod;
                if (!t1 && t2) (f[1][j][mask] += f[1][j - 1][mask ^ (1 << (j - 1))]) %= mod;
                if (!t1 && !t2) (f[1][j][mask] += f[1][j - 1][mask ^ (1 << j)] + f[1][j - 1][mask ^ (1 << (j - 1))]) %= mod;
            }
        }
        
        for (int mask = 0; mask < (1 << (11)); mask ++) f[0][m][mask] = f[1][m][mask];
    }
 
    cout << f[1][m][0];
}
