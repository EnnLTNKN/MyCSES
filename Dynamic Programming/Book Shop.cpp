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
    int n, S; cin >> n >> S;
    vector<int> h(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> h[i];
    for (int i = 1; i <= n; i ++) cin >> s[i];
 
    vector<int> prev(S + 1), cur(S + 1);
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= S; j ++){
            cur[j] = prev[j];
            if (j >= h[i]) cur[j] = max(cur[j], prev[j - h[i]] + s[i]);
        }
        for (int j = 0; j <= S; j ++) prev[j] = cur[j];
    }
    
    cout << *max_element(cur.begin() + 1, cur.end());
 
}