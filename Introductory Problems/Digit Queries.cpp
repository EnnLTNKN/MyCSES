#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int q; cin >> q;
 
    function<int(int)> getNumDigit = [&](int n){
        int cnt = 0; while (n) n /= 10, cnt ++;
        return cnt;
    };
 
    function<int(int, int)> getDigit = [&](int n, int k){
        int s = getNumDigit(n);
        for (int i = 1; i <= s - k; i ++) n /= 10;
        
        return n % 10;
    };
 
    function<int(int, int)> pW = [&](int a, int b){
        int cur = a, res = 1;
        for (int i = 0; (1 << i) <= b; i ++, cur *= cur)
            if (b >> i & 1) res *= cur;
        return res;
    };
 
    while (q --) {
        int k; cin >> k;
        if (k < 10) { cout << k << "\n" ; continue; }
 
        int sum = 0, t = 1; while (sum + 9 * pW(10, t - 1) * t + 1 <= k) sum += 9 * pW(10, t - 1) * (t ++);
        int remain = k - sum;
        int curnum = pW(10, t - 1) + remain / t - (remain % t == 0);
        int curpos = remain % t; if (curpos == 0) curpos = t;
        cout << getDigit(curnum, curpos) << "\n";
    }
}
