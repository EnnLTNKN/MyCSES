#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n ; i ++) cin >> a[i];
    
    int ans = 1e18;
    for (int i = 0; i <= ((1 << n) - 1); i ++){
        int A = 0, B = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) A += a[j];
            else B += a[j];
        }
        ans = min(ans, abs(A - B));
    }
 
    cout << ans;
}