#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int32_t main(){
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int cur = 0, ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += max(0ll, cur - a[i]);
        cur = max(cur, a[i]);
    }
 
    cout << ans;    
}