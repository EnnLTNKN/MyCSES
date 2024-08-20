#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int n; cin >> n;
    vector<string> ans = {"0", "1"};
    for (int i = 2; i <= n; i ++){
        vector<string> nxt = ans; 
        reverse(nxt.begin(), nxt.end());
        for (auto &c: ans) c = "0" + c;
        for (auto &c: nxt) c = "1" + c, ans.push_back(c);
    }
 
    for (auto c: ans) cout << c << "\n";
    
}
