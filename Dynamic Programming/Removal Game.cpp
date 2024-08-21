#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 5e3 + 1;
int s[maxn], a[maxn], f[maxn][maxn][2];
int get(int l, int r){
    return s[r] - s[l - 1];
}
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
 
    memset(f, -1, sizeof f);
    function<int(int, int, bool)> Try = [&](int l, int r, bool turn){
        if (l == r) return f[l][r][turn] = a[l];
        if (f[l][r][turn] != -1) return f[l][r][turn];
        f[l][r][turn] = max({
            get(l + 1, r) - Try(l + 1, r, turn ^ 1) + a[l],
            get(l, r - 1) - Try(l, r - 1, turn ^ 1) + a[r]
        }); 
 
        return f[l][r][turn];
    };
 
    cout << Try(1, n, 0);
}
