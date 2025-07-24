#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll


void solve() {
    int n, A, B; cin >> n >> A >> B;

    vector<int> v(n + 5);
    vector<int> vis(n + 5, 0);

    for(int i = 1; i <= n; ++ i) cin >> v[i];

    auto check = [&](int x) -> bool {
        if(x <= 0 || x > n || vis[x] == 1) return false;
        return true;
    };

    auto bfs = [&](int x) -> int {
        queue<pair<int, int>> q;
        q.push({x, 0});

        while(q.size()) {
            auto [dep, op] = q.front(); q.pop();
            if(dep == B) return op;
            vis[dep] = 1;
            if(check(dep + v[dep])) {
                q.push({dep + v[dep], op + 1});
                vis[dep + v[dep]] = 1;
            }
            if(check(dep - v[dep])) {
                q.push({dep - v[dep], op + 1});
                vis[dep - v[dep]] = 1;
            }
        }
        return -1;
    };
    cout << bfs(A);

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