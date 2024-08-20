#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<char, int> cnt;
    string s; cin >> s;
    for (auto c: s) cnt[c] ++;
    vector<char> ans, remain;
    for (int i = 'A'; i <= 'Z'; i ++){
        if (cnt[i] % 2) remain.push_back(i);
        for (int j = 1; j <= cnt[i] / 2; j ++) ans.push_back(i);
    }
 
    if (remain.size() > 1) return cout << "NO SOLUTION", 0;
    if (remain.size() == 1){
        for (int i = 0; i < ans.size(); i ++) cout << ans[i];
        cout << remain[0];
        for (int i = ans.size() - 1; i >= 0; i --) cout << ans[i];
    }
    else {
        for (int i = 0; i < ans.size(); i ++) cout << ans[i];
        for (int i = ans.size() - 1; i >= 0; i --) cout << ans[i];
    }
}
