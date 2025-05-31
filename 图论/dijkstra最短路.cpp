/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int N = 1e5+5, inf = 0x3f3f3f3f;

struct Dijkstra {
    struct Edge { int v, w; };
    int n;
    vector<vector<Edge>> G;
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
    int n, m, s; cin >> n >> m >> s;
    Dijkstra dij(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dij.add(u, v, w);
    }
    dij.dijkstra(s);
    for(int i = 1; i <= n; ++i) {
        cout << dij.d[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}