#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// luogu P1379

int bfs(string s) {
    map<string, int> mp;
    queue<string> q;
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    q.push(s);
    string end = "123804765";

    while (q.size()) {
        auto s = q.front(); q.pop();
        if (s == end) return mp[s];
        int k = s.find('0');
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; ++ i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            int dis = mp[s];
            swap(s[k], s[a * 3 + b]);
            if (!mp.count(s)) mp[s] = dis + 1, q.push(s);
            swap(s[k], s[a * 3 + b]);
        }
    }
}

void solve() {

    string s; cin >> s;

    cout << bfs(s);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}