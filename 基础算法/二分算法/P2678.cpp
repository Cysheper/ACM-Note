#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n, num, m; cin >> n >> num >> m;
    vector<int> v(num + 1, 0);
    for(int i = 1; i <= num; ++ i) cin >> v[i];
    v.push_back(n);
    int l = 0, r = n + 5;
    auto check = [&](int x) -> bool {
        int last = 0, now = 0;
        int cnt = 0;
        for(int i = 1; i <= num + 1; ++ i) {
            now = v[i];
            if(now - last >= x) {
                last = now;
            } else cnt ++;
        }
        return cnt <= m;
    };
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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