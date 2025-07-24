#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

void solve() {
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &i: v) cin >> i;
    int sx = 0, sy = 0;
    map<char, vector<pair<int, int>>> mp;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j) {
            if(v[i][j] == '@') {
                sx = i; sy = j;
                vis[i][j] = 1;
            }
            if(v[i][j] >= 'A' && v[i][j] <= 'Z') {
                mp[v[i][j]].push_back({i, j});
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    vector<int> wx = {-1, 0, 1, 0};
    vector<int> wy = {0, -1, 0, 1};

    auto check = [&](int x, int y) -> int {
        if(x < 0 || x >= n || y < 0 || y >= m) return 0;
        if(v[x][y] == '#' || vis[x][y] == 1) return 0;
        if(v[x][y] == '.') return 1;
        if(v[x][y] >= 'A' && v[x][y] <= 'Z') return 2;
        if(v[x][y] == '=') return 3;
        return 0;
    };

    while(q.size()) {
        auto [site, dep] = q.front(); q.pop();
        auto [x, y] = site;
        for(int a = 0; a < 4; ++ a) {
            int i = wx[a], j = wy[a];
            int ans = check(x + i, y + j);
            if(ans == 0) continue;
            if(ans == 3) {
                cout << dep + 1 << "\n";
                return;
            } else if(ans == 1) 
                q.push({{x + i, y + j}, dep + 1});
            else if(ans == 2) {
                if(mp[v[x + i][y + j]][0] == make_pair(x + i, y + j)) {
                    q.push({mp[v[x + i][y + j]][1], dep + 1});
                    auto [x1, y1] = mp[v[x + i][y + j]][1];
                }
                else {
                    q.push({mp[v[x + i][y + j]][0], dep + 1});
                    auto [x1, y1] = mp[v[x + i][y + j]][0];
                }
            }  
            vis[x + i][y + j] = 1;
        }
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