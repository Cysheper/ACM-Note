#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n, num, m; cin >> n >> num >> m;
    vector<int> v(num + 1);
    for(int &i: v) cin >> i;
    int l = 0, r = n + 1;
    
    auto check = [&](int x) -> bool {
        for(int i = 0; i < num; ++ i) {
            
        }
    };

    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }

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