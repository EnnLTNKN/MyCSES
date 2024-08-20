#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t; cin >> t;
    while (t --){
        int a, b; cin >> a >> b;
        if ((2 * a - b) % 3 || 2 * a - b < 0){
            cout << "NO\n"; continue;
        }
 
        int y = (2 * a - b) / 3;
        int x = a - 2 * y;
 
        if (x < 0){
            cout << "NO\n"; continue;
        }
 
        cout << "YES\n";
    }
}
