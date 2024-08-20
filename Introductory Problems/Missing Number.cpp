#include<bits/stdc++.h>
using namespace std;
bool app[200010];
int main(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n - 1; i ++){
        cin >> a[i];
        app[a[i]] = 1;
    }
 
    for (int i = 1; i <= n; i ++) 
        if (!app[i]) cout << i;
}
