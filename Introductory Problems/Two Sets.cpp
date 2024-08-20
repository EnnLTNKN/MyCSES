#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a[2];;
    if (n % 2 == 0){
        if ((n / 2) % 2) return cout << "NO", 0;
        else {
            int i = 1, j = n, t = 1;
            while (i < j){
                a[t].push_back(i ++), a[t].push_back(j --);
                t ^= 1;
            }
        }
    }
 
    else {
        if ((n / 2) % 2 == 0) return cout << "NO", 0;
        int i = 1, j = n - 1, t = 1;
        while (i < j){
            a[t].push_back(i ++), a[t].push_back(j --);
            t ^= 1;
        }
 
        a[t].push_back(n);
    }
 
    sort(a[0].begin() + 1, a[0].end());
    sort(a[1].begin() + 1, a[1].end());
 
    cout << "YES\n" << a[0].size() << "\n";
    for (int i: a[0]) cout << i << " ";
    cout << "\n" << a[1].size() << "\n";
    for (int i: a[1]) cout << i << " ";
}