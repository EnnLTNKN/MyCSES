#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t --){
        int x, y; cin >> x >> y;
        if (x < y){
            if (y % 2 == 0) cout << (y - 1) * (y - 1) + x;
            else cout << y * y - x + 1;
        }
 
        else {
            if (x % 2 == 0) cout << x * x - y + 1;
            else cout << (x - 1) * (x - 1) + y;
        }
 
        cout << "\n";
    }
}