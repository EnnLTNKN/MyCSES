#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int n = s.size() - 1;
    vector<char> ans(n + 1);
    vector<int> used(n + 1);
    set<string> res;
    
    function<void(int)> Try = [&](int i){
        for (int j = 0; j <= n; j ++){
            if (!used[j]){
                used[j] = 1;
                ans[i] = s[j];
                if (i == n) {
                    string tmp; for (auto c: ans) tmp += c;
                    res.insert(tmp);
                }
                else Try(i + 1);
                used[j] = 0;
            }
        }
    };
 
    Try(0);
    cout << res.size() << "\n";
    for (auto c: res) cout << c << "\n";
}
