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
    vector<vector<int>> f(501, vector<int> (501, -1));
    int a, b; cin >> a >> b;
 
    function<int(int, int)> get = [&](int a, int b){
        
        if (a > b) swap(a, b);
 
        if (f[a][b] != -1) return f[a][b];
        if (a == b) return 0ll;
 
        int &res = f[a][b]; res = a * b;
        for (int i = 1; i < a; i ++) res = min(res, get(i, b) + get(a - i, b) + 1);
        for (int i = 1; i < b; i ++) res = min(res, get(a, i) + get(a, b - i) + 1);
 
        return res;
    };
 
    cout << get(a, b);    
}