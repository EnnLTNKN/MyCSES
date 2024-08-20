#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<char>> a(9, vector<char> (9));
    for (int i = 1; i <= 8; i ++) for (int j = 1; j <= 8; j ++) cin >> a[i][j];
    vector<bool> col(9), dia1(16), dia2(16);
 
    function<int(int)> Try = [&](int i){
        int ans = 0;
        for (int j = 1; j <= 8; j ++){
            if (!col[j] && !dia1[i - j + 8] && !dia2[i + j - 1] && a[i][j] == '.'){
                col[j] = dia1[i - j + 8] = dia2[i + j - 1] = 1;
                if (i == 8) ans ++;
                else ans += Try(i + 1);
                col[j] = dia1[i - j + 8] = dia2[i + j - 1] = 0;
            }
        }
 
        return ans;
    };
 
    cout << Try(1);
    
}
