/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
const int maxn = 1e3 + 1;
int a[maxn][maxn], n, m, f[maxn][maxn];
 
void update(int x, int y, int val){
    for (; x <= n; x += x & -x)
        for (int Y = y; Y <= n; Y += Y & -Y) f[x][Y] += val;
}
 
int get(int x, int y){
    int sum = 0;
    for (; x; x -= x & -x) for (int Y = y; Y; Y -= Y & -Y) sum += f[x][Y];
    return sum;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    // freopen("enn.inp", "r", stdin);
    // freopen("enn.out", "w", stdout);
 
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++){
        char c; cin >> c;
        a[i][j] = (c == '*'); 
        update(i, j, a[i][j]);
    }
 
    while (m --){
        int t; cin >> t;
        if (t == 1){
            int x, y; cin >> x >> y;
            if (a[x][y] == 1) update(x, y, -1);
            else update(x, y, 1);
            a[x][y] ^= 1;
        }
 
        else {
            int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
            cout << get(i2, j2) - get(i2, j1 - 1) - get(i1 - 1, j2) + get(i1 - 1, j1 - 1) << "\n";
        }
    }
 
 
    
}