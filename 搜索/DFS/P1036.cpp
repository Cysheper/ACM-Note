#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);

    for(int &i: v) cin >> i;

    auto check = [&](int x) -> bool {
        if(x < 2) return false;
        for(int i = 2; i <= x / i; ++ i) {
            if(x % i == 0) return false;
        }
        return true;
    };

    int ans = 0;
    function<void(int, int, int)> dfs = [&](int x, int dep, int a) {
        if(dep == k) {
            if(check(x)) ans ++;
            return;
        }
        for(int i = a; i < n; ++ i) {
            dfs(x + v[i], dep + 1, i + 1);
        }
    };
    dfs(0, 0, 0);
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