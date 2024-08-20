#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define pii pair<int, int>
pii H[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7, maxn = 20;
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), s(n + 1); for (int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    while (q --){
        int l, r; cin >> l >> r;
        cout << s[r] - s[l - 1] << "\n";
    }
}
