#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= 6; i ++) f[i] = 1;
 
    int mod = 1e9 + 7;
    for (int i = 1; i <= n; i ++){
        for (int j = i - 1; j >= max(i - 6, 1ll); j --){
            (f[i] += f[j]) %= mod;;
        }
    }
 
    cout << f[n];
}