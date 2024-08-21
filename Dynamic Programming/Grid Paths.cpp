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
    vector<vector<char>> a(n + 1, vector<char> (n + 1));
    vector<vector<int>> f(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) cin >> a[i][j];
    f[1][1] = (a[1][1] == '.');
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++){
        if (i == 1 && j == 1) continue;
        if (a[i][j] == '.') f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
    }
 
    cout << f[n][n];
}