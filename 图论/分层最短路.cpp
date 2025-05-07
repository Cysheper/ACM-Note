#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define inf 0x3f3f3f3f
struct Dijkstra {
    struct node { int v, w; };
    int n;
    vector<vector<node>> G;
    vector<int> d, vis, path, cnt;
    Dijkstra(int _n): n(_n) {
        G.assign(n + 1, {});
        d.assign(n + 1, inf);
        vis.assign(n + 1, 0);
        path.assign(n + 1, -1);
        cnt.assign(n + 1, 0);
    }
    void add(int u, int v, int w) {
        G[u].push_back({v, w});
    }
    void dijkstra(int s) {
        d[s] = 0;
        cnt[s] = 1;
        // 小顶堆，存 {dist, u}
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, s});
        
        while (!pq.empty()) {
            auto [_u, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;

            for (auto &e : G[u]) {
                int v = e.v, w = e.w;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    path[v] = u;
                    cnt[v] = cnt[u];
                    pq.push({d[v], v});
                } else if (d[v] == d[u] + w) {
                    cnt[v] += cnt[u];
                }
            }
        }
    }

    // 获取从 s 到 u 的路径，若无路径返回空向量
    vector<int> getPath(int u, int s) {
        vector<int> res;
        if (d[u] == inf) return res;
        for (int cur = u; cur != -1; cur = path[cur]) {
            res.push_back(cur);
            if (cur == s) break;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


void solve() {
    int n, m, k; cin >> n >> m >> k;
    int s, t; cin >> s >> t;

    Dijkstra dij(n * (k + 1));
    for(int i = 0, a, b, c; i < m ; ++ i) {
        cin >> a >> b >> c;
        dij.add(a, b, c);
        dij.add(b, a, c);

        for(int j = 1; j <= k; ++ j) {
            dij.add(a + j * n, b + j * n, c);
            dij.add(b + j * n, a + j * n, c);
            dij.add(a + (j - 1) * n, b + j * n, 0);
            dij.add(b + (j - 1) * n, a + j * n, 0);
        }
    }

    dij.dijkstra(s);
    int ans = inf;
    for(int j = 0; j <= k; ++ j) 
        ans = min(ans, dij.d[t + j * n]);

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}