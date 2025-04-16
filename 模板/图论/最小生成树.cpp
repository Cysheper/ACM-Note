/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 2e5 + 10;
// 并查集

class DSU {
private:
    int par[N],rk[N];
public:
    // 初始化n个元素
    void init(int n) {
        for(int i = 1;i <= n;++i) par[i] = i, rk[i] = 0;
    }
    // 查询树的根 (路径压缩)
    int find(int x) {
        return par[x] = par[x] == x ? x : find(par[x]);
    }
    // 普通合并
    int unite(int x, int y) {
        x = find(x);y = find(y);
        return x == y ? 0 : par[x] = y;
    }
    // 按秩合并
    void merge(int x, int y) {
        x = find(x);y = find(y);
        if(x == y) return;
        if(rk[x] > rk[y]) swap(x, y);
        par[x] = y;
        if(rk[x] == rk[y]) rk[y]++;
    }
    // 判断x和y是否联通
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
// 最小生成树 kruskal算法
class MST : DSU {
private:
    struct edge{
        int u, v, cost;
        bool operator<(const edge& other) const {
            return cost < other.cost; // 按权值升序排序
        }
    };
    
    vector<edge> es; // 边集
    vector<edge> mst; //最小生成树边集
    int V, res; //V:点数 res:MST各边长之和
public:
    MST(int n) : V(n) {} // 构造函数, 赋值V为n
    int kruskal() {
        sort(es.begin(), es.end());
        init(V);
        mst.clear();
        res =  0;
        for(auto &e : es) {
            if(!same(e.u, e.v)) {
                unite(e.u, e.v);
                mst.push_back(e);
                res += e.cost;
            }
        }
        return res;
    }
    // 加边, 权
    void addedge(int u, int v, int cost) {
        es.push_back({u, v, cost});
    }
    // 判断是否连通, 先要使用kruskal算法
    bool isConnected() {
        set<int> st;
        for (int i = 1; i <= V; ++i) {
            st.insert(find(i));
        }
        return st.size() == 1;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    MST mst(n);
    for (int i=0;i<m;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mst.addedge(a, b, c);
    }
    int ans = mst.kruskal();
    if(mst.isConnected())
        cout << ans;
    else cout << "orz";
}   
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}