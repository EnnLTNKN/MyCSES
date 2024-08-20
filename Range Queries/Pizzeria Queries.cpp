/*                                          ᴷᴺ✞ঔৣ۝NoNameCoder                                               */
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
 
const int maxn = 2e5 + 1;
int n, q, fLeft[maxn * 4], fRight[maxn * 4];
void updateLeft(int i, int l, int r, int p, int val){
    if (l > p || r < p) return;
    if (l == r) return void(fLeft[i] = val - p);
    int mid = (l + r) >> 1;
    updateLeft(i * 2, l, mid, p, val);
    updateLeft(i * 2 + 1, mid + 1, r, p, val);
    fLeft[i] = min(fLeft[i * 2], fLeft[i * 2 + 1]);
}
 
void updateRight(int i, int l, int r, int p, int val){
    if (l > p || r < p) return;
    if (l == r) return void(fRight[i] = val + p);
    int mid = (l + r) >> 1;
    updateRight(i * 2, l, mid, p, val);
    updateRight(i * 2 + 1, mid + 1, r, p, val);
    fRight[i] = min(fRight[i * 2], fRight[i * 2 + 1]);
}
 
int getLeft(int i, int l, int r, int u, int v){
    if (l > v || r < u) return 1e18;
    if (u <= l && r <= v) return fLeft[i];
    int mid = (l + r) >> 1;
    return min(getLeft(i * 2, l, mid, u, v), getLeft(i * 2 + 1, mid + 1, r, u, v));
}
 
int getRight(int i, int l, int r, int u, int v){
    if (l > v || r < u) return 1e18;
    if (u <= l && r <= v) return fRight[i];
    int mid = (l + r) >> 1;
    return min(getRight(i * 2, l, mid, u, v), getRight(i * 2 + 1, mid + 1, r, u, v));
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define name "enn"
//    FILE
 
    cin >> n >> q;
    FOR(i, 1, n){
        int x; cin >> x;
        updateLeft(1, 1, n, i, x);
        updateRight(1, 1, n, i, x);
    }
 
    while (q --){
        int t; cin >> t;
        if (t == 1){
            int k, x; cin >> k >> x;
            updateLeft(1, 1, n, k, x);
            updateRight(1, 1, n, k, x);
        }
 
        else {
            int pos; cin >> pos;
            cout << min(getLeft(1, 1, n, 1, pos) + pos, getRight(1, 1, n, pos, n) - pos) << "\n";
        }
    }
}