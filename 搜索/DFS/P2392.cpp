#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    vector<int> s;
    for(int i = 0; i < 4; ++ i) {
        int num; cin >> num;
        s.push_back(num);
    }
    int L = 0, R = 0;
    int mn = INT_MAX, ans = 0;
    function<void(int, vector<int>, int)> dfs = [&](int x, vector<int> v, int y) {
        if(x > y) {
            mn = min(mn, max(L, R));
            return;
        }
        L += v[x - 1];
        dfs(x + 1, v, y);
        L -= v[x - 1];
        R += v[x - 1];
        dfs(x + 1, v, y);
        R -= v[x - 1];
    };

    for(int &i: s) {
        vector<int> v(i);
        for(int &j: v) cin >> j;
        mn = INT_MAX;
        dfs(1, v, i);
        ans += mn;
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