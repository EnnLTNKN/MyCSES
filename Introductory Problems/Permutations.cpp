#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n; cin >> n;
    if (n == 1) return cout << 1, 0;
    if (n <= 3) return cout << "NO SOLUTION", 0;
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
}