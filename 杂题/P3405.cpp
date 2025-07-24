#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n; cin >> n;
    map<pair<string, string>, int> mp;
    int ans = 0;

    while(n --) {
        string a, b; cin >> a >> b;
        int num = mp[{b, a.substr(0, 2)}];
        if(num != 0) ans += num;
        mp[{a.substr(0, 2), b}] ++;
    }
    cout << ans << "\n";
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