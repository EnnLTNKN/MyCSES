#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin >> s;
    s = "$" + s, n = s.size() - 1;
    int best = 1, cur = 1;
    for (int i = 1; i <= n; i ++){
        if (s[i] == s[i - 1]) cur ++;
        else best = max(best, cur), cur = 1;
    }
 
    best = max(best, cur);
    cout << best;
}