#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n, mod = 1e9 + 7; cin >> n;
    int ans = 1;
    for (int i = 0, cur = 2; i <= 20; i ++, cur = cur * cur % mod){
        if (n >> i & 1) ans = ans * cur % mod;
    }
 
    cout << ans;
}