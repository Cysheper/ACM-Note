#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int p = 131;
int hash(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); ++ i) {
        ans = ans * p + s[i];
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    

}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1; 
    // cin >> _;
    while(_ --) solve();
    return 0;
}