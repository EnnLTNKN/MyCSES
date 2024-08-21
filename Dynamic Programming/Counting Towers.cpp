#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7;
 
int f[1000100][2];
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= 1000000; i ++) f[i][0] = (2 * f[i - 1][0] + f[i - 1][1]) % mod, f[i][1] = (f[i - 1][0] + 4 * f[i - 1][1]) % mod;
 
    int t; cin >> t;
    while (t --){
        int n; cin >> n;
        cout << (f[n][0] + f[n][1]) % mod << "\n";
    }
}