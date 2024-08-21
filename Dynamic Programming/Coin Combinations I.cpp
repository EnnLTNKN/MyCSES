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
    int n, s; cin >> n >> s;
    vector<int> a(n); for (auto &x: a) cin >> x;
    vector<int> f(s + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= s; i ++){
        for (int x: a){
            if (i >= x) (f[i] += f[i - x]) %= mod;
        }
    }
 
    cout << f[s];
}