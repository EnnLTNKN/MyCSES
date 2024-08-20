#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define All(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define FORD(i, a, b) for (int i = a; i >= b; i --)
#define FILE freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
#define fi first
#define se second
int Hx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int Hy[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int mod = 1e9 + 7, inf = 1e18;
template<class A, class B> bool maximize(A &a, B b) { return a < b && (a = b, true); }
template<class A, class B> bool minimize(A &a, B b) { return a > b && (a = b, true); }
/*                                          ᴷᴺ✞ঔৣ۝NoNameCoder                                               */
 
const int maxn = 2e5 + 1;
int f[4 * maxn + 1];
 
int jump(int i, int l, int r, int k){
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (f[i * 2] >= k) return jump(i * 2, l, mid, k);
    return jump(i * 2 + 1, mid + 1, r, k - f[i * 2]);
}
 
void update(int i, int l, int r, int p){
    if (l > p || r < p) return;
    if (l == r) return void(f[i] ^= 1);
    int mid = (l + r) >> 1;
    update(i * 2, l, mid, p);
    update(i * 2 + 1, mid + 1, r, p);
    f[i] = f[i * 2] + f[i * 2 + 1];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
    
    int n; cin >> n;
    vector<int> a(n + 1); FOR(i, 1, n) cin >> a[i], update(1, 1, n, i);
    FOR(i, 1, n){
        int x; cin >> x;
        int index = jump(1, 1, n, x);
        cout << a[index] << " ";
        update(1, 1, n, index); 
    }
}