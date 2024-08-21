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
    vector<int> f(n + 1, INT_MAX);
    f[0] = 0;
    for (int i = 1; i <= n; i ++){
        int x = i;
        while (x){
            f[i] = min(f[i], f[i - x % 10] + 1);
            x /= 10;
        }
    }
 
    cout << f[n];
}