#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n, m, k; cin >> n >> m >> k;

    double l = 0, r = 305;
    auto check = [&](double x) -> bool {
        double sum = 0, v = 1;
        for(int i = 1; i <= k; ++ i) {
            v *= (1 + x);
            sum += (m / v);
        }
        if(sum > n) return true;
        return false;
    };

    while(r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.1lf", l*100);
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