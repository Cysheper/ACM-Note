#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10 + 10;  // 假设树有最大 1e5 个节点
const int LOG = 17;        // 二进制提升的层数，log2(1e5)约为16.61，取17就足够

class LCA {
public:
    vector<int> G[MAXN];    // 邻接表表示树
    int par[MAXN][LOG];     // parent[u][i]表示u的2^i祖先
    int dep[MAXN];          // 深度数组
    int n;                  // 节点数
    // 构造函数
    LCA(int n) {
        this->n = n;
        memset(par, -1, sizeof(par));
        memset(dep, -1, sizeof(dep));
    }
    // 深度优先搜索DFS，预处理父节点和深度信息
    void dfs(int u, int p) {
        par[u][0] = p;    
        for (int i = 1; i < LOG; ++i) {
            if (par[u][i - 1] != -1)
                par[u][i] = par[par[u][i - 1]][i - 1];  
        }
        for (int v : G[u]) {
            if (v != p) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    }
    // 加边
    void addedge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // 查找节点u和v的最近公共祖先
    int queryLCA(int u, int v) {
        // 如果u的深度较大，交换u和v
        if (dep[u] < dep[v]) swap(u, v);
        // 将u和v调整到同一深度
        for (int i = LOG - 1; i >= 0; --i) {
            if (dep[u] - (1 << i) >= dep[v]) {
                u = par[u][i];
            }
        }
        if (u == v) return u;  // 如果u和v已经相同，则返回
        // 同时上升u和v直到它们的父节点相同
        for (int i = LOG - 1; i >= 0; --i) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        // 返回u和v的父节点，也就是最近公共祖先
        return par[u][0];
    }
    // 初始化树 init(n) n为树的根
    void init(int root) {
        dep[root] = 0;
        dfs(root, -1);  // 从根节点开始DFS预处理
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    LCA lca(n);  // 创建 LCA 类实例
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        lca.addedge(u, v);  // 添加树的边
    }
    lca.init(s);  // 初始化树并进行DFS预处理
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca.queryLCA(u, v) << '\n';  // 查询并输出最近公共祖先
    }

    return 0;
}
