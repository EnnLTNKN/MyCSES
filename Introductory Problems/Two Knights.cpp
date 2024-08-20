#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++){
        if (i == 1) cout << 0 << "\n";
        else if (i == 2) cout << 6 << "\n";
        else if (i == 3) cout << 28 << "\n";
        else {
            int ans = 48 + 40 * (i - 4) + 8 * (i * i - 8 * (i - 4) - 16);
            cout << i * i * (i * i - 1) / 2 - ans / 2 << "\n"; 
        }
    }   
}