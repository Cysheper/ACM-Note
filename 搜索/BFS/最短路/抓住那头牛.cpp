#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;

int bfs(int x, int y) {
    vector<int> dis(N + 5, -1);
    queue<int> q; q.push(x);
    dis[x] = 0;
    while(q.size()) {
        int x = q.front(); q.pop();
        if (x + 1 < N && dis[x + 1] == -1) {
            dis[x + 1] = dis[x] + 1;
            q.push(x + 1);
        }
        if (x - 1 > 0 && dis[x - 1] == -1) {
            dis[x - 1] = dis[x] + 1;
            q.push(x - 1);
        }
        if (x * 2 < N && dis[x * 2] == -1) {
            dis[x * 2] = dis[x] + 1;
            q.push(x * 2);
        }
        if(x == y) return dis[y];
    }
    return -1;
}

void solve() {
    int x, y; cin >> x >> y;

    cout << bfs(x, y) << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _; cin >> _;
    while(_--) solve();

    return 0;
}