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
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<bool> f(100001);
    f[0] = 1;
    for (int x: a){
        for (int i = 100000; i >= x; i --){
            f[i] = f[i] | f[i - x];
        }
    }
 
    vector<int> ans;
    for (int i = 1; i <= 100000; i ++) if (f[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for (int i: ans) cout << i << " ";
}