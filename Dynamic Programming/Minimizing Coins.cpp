#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, s; cin >> n >> s;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> f(s + 1, INT_MAX);
    f[0] = 0;
    for (int i = 1; i <= s; i ++){
        for (int x: a){
            if (i >= x) f[i] = min(f[i], f[i - x] + 1);
        }
    }
 
    cout << ((f[s] == INT_MAX) ? -1 : f[s]);
}