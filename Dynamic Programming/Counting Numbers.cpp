#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
const int mod = 1e9 + 7, maxn = 20;
 
int f[20][2][10][2];
int get(int i, bool tight, int lst, bool leadingZero, string &a, int num){
    if (i > a.size() - 1) {
        return 1ll;
    }
 
    int &res = f[i][tight][lst][leadingZero];
    if (res != -1) return res;
 
    res = 0; int maxD = (tight) ? a[i] - '0' : 9;
    for (int D = 0; D <= maxD; D ++){
        int nwtight = (tight && D == maxD);
        if (!leadingZero && lst == D) continue;
        res += get(i + 1, nwtight, D, leadingZero && (D == 0), a, num * 10 + D);
    }
 
    return res;
}
 
int getVal(string &a){
    memset(f, -1, sizeof f);
    return get(0, 1, -1, 1, a, 0);
}
 
int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b; cin >> a >> b;
    int ans = getVal(b) - getVal(a) + 1;
    for (int i = 0; i < a.size() - 1; i ++) if (a[i] == a[i + 1]) {ans --; break;}
 
    cout << ans;
}