#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

struct Edge {
    int to, w, c;
};

int n, m, k, s, t;
vector<Edge> graph[2005];
int dist[2005][1 << 9]; // 最多 9 种命途

int count_bits(int mask) {
    return __builtin_popcount(mask);
}

int ceil_half(int w) {
    return (w + 1) / 2;
}

int dijkstra() {
    using T = tuple<int, int, int>; // (时间, 当前节点, mask)
    priority_queue<T, vector<T>, greater<T>> pq;

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < (1 << 9); ++j)
            dist[i][j] = INF;

    dist[s][0] = 0;
    pq.emplace(0, s, 0);

    while (!pq.empty()) {
        auto [d, u, mask] = pq.top(); pq.pop();
        if (dist[u][mask] < d) continue;
        for (auto& e : graph[u]) {
            int to = e.to, w = e.w, c = e.c;
            int cost, next_mask = mask;

            if (mask & (1 << (c - 1))) {
                cost = ceil_half(w); // 重复命途类型
            } else {
                cost = w;
                if (count_bits(mask) < k) {
                    next_mask = mask | (1 << (c - 1));
                } else {
                    continue; // 不能再加新的命途类型
                }
            }

            if (dist[to][next_mask] > d + cost) {
                dist[to][next_mask] = d + cost;
                pq.emplace(dist[to][next_mask], to, next_mask);
            }
        }
    }

    int res = INF;
    for (int i = 0; i < (1 << 9); ++i) {
        res = min(res, dist[t][i]);
    }

    return res == INF ? -1 : res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        graph[u].push_back({v, w, c});
        graph[v].push_back({u, w, c});
    }

    cout << dijkstra() << "\n";
    return 0;
}
