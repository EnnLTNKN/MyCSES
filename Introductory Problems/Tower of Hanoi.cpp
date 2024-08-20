#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    #define pii pair<int, int>
    vector<pii> ans;
    function<void(int, int, int, int)> Try = [&](int n, int l, int mid, int r){
        if (n == 1) {
            ans.push_back(pii(l, r));
            return;
        }
        Try(n - 1, l, r, mid);
        ans.push_back(pii(l, r));
        Try(n - 1, mid, l, r);
    };
 
    int n; cin >> n;
    Try(n, 1, 2, 3);
    cout << ans.size() << "\n";
    for (auto [x, y]: ans) cout << x << " " << y << "\n";
