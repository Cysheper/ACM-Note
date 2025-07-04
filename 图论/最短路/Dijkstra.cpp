#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
// #define int ll

struct Dijkstra {
    struct node { int v; int w; };
    vector<vector<node>> G; 
    vector<int> d, vis;     // 原点到点x的最短路为d[x]

    Dijkstra(int n) {
        G.assign(n + 1, {}); 
        d.assign(n + 1, INT_MAX);
        vis.assign(n + 1, 0);
    }

    void add(int u, int v, int w) {
        G[u].push_back({v, w});
    }   

    void dijkstra(int s) {
        d[s] = 0;

        priority_queue<pii, vector<pii>, greater<>> q;
        q.push({0, s});

        while(q.size()) {
            int u = q.top().second; 
            q.pop();

            if(vis[u]) continue;
            vis[u] = 1;

            for(auto e: G[u]) {
                auto [v, w] = e;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    q.push({d[v], v});
                }
            }
        }
    }
};

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra dij(n);
    while(m --) {
        int u, v, w;
        cin >> u >> v >> w;
        dij.add(u, v, w);
    }

    dij.dijkstra(s);
    
    for(int i = 1; i <= n; ++ i) {
        cout << dij.d[i] << " ";
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