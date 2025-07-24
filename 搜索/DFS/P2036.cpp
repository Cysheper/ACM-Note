#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(auto &[s, b]: v) cin >> s >> b;

    int S = 1, B = 0, mn = INT_MAX; 

    function<void(int)> dfs = [&](int a) {
        if(a != 0) mn = min(mn, abs(S - B));
        for(int i = a; i < n; ++ i) {
            S *= v[i].first;
            B += v[i].second;
            dfs(i + 1);
            S /= v[i].first;
            B -= v[i].second;
        }
    };
    dfs(0);
    cout << mn << "\n";
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