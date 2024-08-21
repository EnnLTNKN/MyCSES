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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> prev(m + 2), cur(m + 2);
 
    for (int i = 1; i <= n; i ++) cin >> a[i];
    
    if (a[1] == 0) for (int i = 1; i <= m; i ++) prev[i] = 1;
    else prev[a[1]] = 1;
 
    for (int i = 2; i <= n; i ++){
        if (a[i]){
            (cur[a[i]] += prev[a[i] - 1]) %= mod;
            (cur[a[i]] += prev[a[i]]) %= mod;
            (cur[a[i]] += prev[a[i] + 1]) %= mod;
        }
 
        else{
            for (int j = 1; j <= m; j ++){
                (cur[j] += prev[j - 1]) %= mod;
                (cur[j] += prev[j]) %= mod;
                (cur[j] += prev[j + 1]) %= mod;
            }
        }
 
        for (int j = 1; j <= m; j ++){
            prev[j] = cur[j];
            cur[j] = 0;
        }
    }
 
    int sum = 0;
    for (int i = 1; i <= m; i ++) sum = (sum + prev[i]) % mod;
    cout << sum;
}