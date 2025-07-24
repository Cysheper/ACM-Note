#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int L, N, K; cin >> L >> N >> K;
    vector<int> v(N);
    for(int &i: v) cin >> i;

    auto check = [&](int x) -> bool {
        int last = 0, now = 0, cnt = 0;
        for(int i = 0; i < N; ++ i) {
            now = v[i];
            if(now - last > x) {
                cnt += (now - last) / x;
                if((now - last) % x == 0) cnt --;
            } 
            last = now;
        }
        return cnt <= K;
    };

    int l = 0, r = L;
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";

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