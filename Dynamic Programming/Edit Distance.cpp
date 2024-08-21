#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 5e3 + 1;
int f[maxn][maxn];
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b; cin >> a >> b; a = "$" + a, b = "$" + b;
 
    for (int i = 1; i < a.size(); i ++) f[i][0] = i;
    for (int i = 1; i < b.size(); i ++) f[0][i] = i;
 
    for (int i = 1; i < a.size(); i ++) for (int j = 1; j < b.size(); j ++){
        f[i][j] = f[i - 1][j - 1] + 1;
        if (a[i] == b[j]) f[i][j] --;
 
        f[i][j] = min({f[i][j], f[i - 1][j] + 1, f[i][j - 1] + 1});
    }
 
    cout << f[a.size() - 1][b.size() - 1];
}