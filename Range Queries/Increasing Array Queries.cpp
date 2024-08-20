/*ᴷᴺ✞ঔৣ۝NoNameCoder*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> rbTree;
 
const int maxn = 2e5 + 1;
int a[maxn], nxt[maxn], sum[maxn], f[maxn];
#define pii pair<int, int>
 
void add(int i, int x){
    for (; i < maxn; i += i & -i) f[i] += x;
}
 
int get(int i){
    int sum = 0;
    for (; i; i -= i & -i) sum += f[i];
    return sum;
}
 
int getLR(int l, int r){
    return get(r) - get(l - 1);
}
 
vector<pii> qr[maxn];
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        qr[l].push_back(pii(r, i));
    }
 
    vector<int> ans(q + 1), st;
    st.push_back(n + 1);
 
    for (int i = n; i >= 1; i --){
        while (st.back() != n + 1 && a[st.back()] <= a[i]){
            int j = st.back();
            add(j, -(a[j] * (nxt[j] - j - 1) - sum[nxt[j] - 1] + sum[j]));
            st.pop_back();
        }
 
        nxt[i] = st.back();
        add(i, (a[i] * (nxt[i] - i - 1) - sum[nxt[i] - 1] + sum[i]));
        st.push_back(i);
 
        for (auto [j, id]: qr[i]){
            int l = 1, r = st.size() - 1, lst = i;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (nxt[st[mid]] >= j + 1) l = mid + 1, lst = st[mid];
                else r = mid - 1;
            }
 
            ans[id] = ((i != lst) ? getLR(i, lst - 1) : 0) + a[lst] * (j - lst) - sum[j] + sum[lst];
        }
    }
 
    for (int i = 1; i <= q; i ++) cout << ans[i] << "\n";
}