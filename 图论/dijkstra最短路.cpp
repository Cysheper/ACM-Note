/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
const int N = 1e5+5, inf = 2147483647;
class _dijkstra_ {
private:
    struct edge{   
        int v,w; // v:点 , w:权
    };
    int path[N];// 记录路径
public:
    int n, m; // n个点, m条边
    int d[N], vis[N];  // d[N]存个点到原点最小距离, vis[N]标记是否出圈
    vector<edge> G[N]; // 创建图
    // dijkstra(s), s为起始点 
    void dijkstra(int s) {
        fill(d, d + n + 1, inf);
        d[s] = 0;
        priority_queue<pair<int, int>> q; 
        q.push({0, s});
        while(!q.empty()) {
            auto t = q.top();q.pop();
            int u = t.second;
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto e : G[u]) {
                int v = e.v, w = e.w;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    path[v] = u;
                    q.push({-d[v], v});
                }
            }
        }
    }
    // 递归输出最短路径
    void dfs_path(int u, int s) {
        if(u == s) {
            cout << u;
            return;
        }
        dfs_path(path[u], s);
        cout << u << ' ';
    }
};
void solve() {
    int s;
    _dijkstra_ dij;
    cin >> dij.n >> dij.m >> s;
    for (int i=0;i<dij.m;++i) {
        int v, e, w;
        cin >> v >> e >> w;
        dij.G[v].push_back({e,w});
    }
    dij.dijkstra(s);
    for(int i=1;i<=dij.n;++i) {
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