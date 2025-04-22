/*----------author: Cysheper----------*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll 
#define inf LLONG_MAX/2
#define eps 1e-12
const int N = 2e5 + 5;

/* 对于有大量函数组合或有较大辅助空间的算法, 用类封装 */

/*---------------基础算法---------------*/

//快速幂 res = x ^ n % mod;
int quick_pow(int x, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
// 快读 int a = read();
inline int read() {
    char c = getchar();
    int k = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = k * 10 + c - '0';
        c = getchar();
    }
    return k * f;
}

// 快速排序 qsort(arr); O(nlogn)
class quicksort{
    void sort(int l, int r, vector<int> &arr) {
        if(l == r) return;
        int i = l - 1, j = r + 1, x = arr[(l+r)>>1];
        while(i < j) {
            i++;j--;
            while(arr[i] < x) i++;
            while(arr[j] > x) j--;
            if(i < j) swap(arr[i], arr[j]);
        }
        sort(l, j, arr);
        sort(j + 1, r , arr);
    }
    void qsort(vector<int> &v) {
        sort(0, v.size()-1, v);
    }
};

// 归并排序 msort(arr); O(nlogn)
class MS {
    int b[N];
    int ans = 0; // 求逆序对
    void sort(int l,int r, vector<int> &arr){
        if(l >= r) return;
        int mid = (l + r) >> 1;
        sort(l, mid, arr);
        sort(mid + 1,r,arr);
        int i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) b[k++] = arr[i++];
            else { b[k++] = arr[j++]; ans += mid - i + 1; } 
        }
        while(i <= mid) b[k++] = arr[i++];
        while(j <= r) b[k++] = arr[j++];
        for(int i = l; i <= r; ++i) arr[i] = b[i];
    }
    void msort(vector<int> &v) {
        sort(0, v.size()-1, v);
    }
};

/*---------------基础数学---------------*/

// gcd(a, b) 求a, b最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// lcm(a, b) 求a, b最小公倍数
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// 排列组合
class PC {
    const int p = 998244353;
    //排列数
    int A(int n, int m) {
        int ans = 1;
        for (int i = 1; i <= m; ++i) {
            ans *= n - i + 1;
            ans %= p;
        }
        return ans;
    }
    //组合数 
    int C(int a, int b) {
        int res = 1;
        for (int i = 1, j = a; i <= b; ++i,--j) {
            res = (int) res * j % p;
            res = (int) res * quick_pow(i, p - 2, p) % p;
        }
        return res;
    }
};
// 试除法求第k个约数 O(sqrt(n))
int trial(int n, int k) {
    set<int> st;// 存放n的约数
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            st.insert(i);
            st.insert(n / i);
        }
    }
    if(k > st.size()) return -1;
    else {
        auto it = st.begin();
        advance(it, k - 1);
        return *it;
    }
}
// 欧拉筛求质数 O(nloglogn)
class _ola_{
    bitset<N> bt; //判重
    int primes[N], pp = 0; //primes[N] 存放质数
    void ola(int x) {
        for (int i = 2;i <= x; ++i) {
            if(!bt[i]) primes[++pp] = i;
            for (int j = 1; primes[j] * i <= x; ++j){
                bt[primes[j] * i] = 1;
                if (i % primes[j] == 0) break;
            }
        }
    }
};

/*---------------字符串---------------*/

// KMP (主串，模式串) 返回所有模式串在子串中出现的位置 O(m + n) 
class _KMP_{
    int ne[N];
    void KMP(string S, string P){
        memset(ne, 0, sizeof(ne));
        ll n = P.size(), m = S.size();
        for (int i = 1, j = 0; i < n; ++i) {
        while(j && P[i] != P[j]) j = ne[j-1];
        if (P[i] == P[j]) j++;
            ne[i] = j;
        }
        for (int i = 0, j = 0; i < m; ++i) {
            while(j && S[i] != P[j]) j = ne[j-1];
            if (S[i] == P[j]) j++;
            if(j == n){
                cout << i-n+2 << '\n';
                j = ne[j-1];
            }
        }
    }
};
// 字典树 
class Trie {
    int trie[N][26]; //每个结点都有可能有26个子结点
    int word[N]; //用于记录以这个结点为单词末尾单词个数
    char str[80];
    // n个字符串,最长链长为ans
    int n, tot = 0,ans = 0;
    // 字典树,插入字符串,最长链长为ans
    void insert (char *str) {
        int u = 0; //根结点
        int len = strlen(str);
        int res = 0; //表示字典树路径上存有几个别的单词
        for (int i = 0; i < len;++i) {
            int a = str[i] - 'a'; //映射小写字母
            if (trie[u][a] == 0) //如果没有这个结点
                trie[u][a] = ++tot;
            u = trie[u][a]; //跳转到该结点
            res += word[u]; //如果这个结点存有单词则增加
        }
        word[u]++; //以该结点结尾的单词的个数加一
        if (res + 1 > ans) //比较链长最大值
            ans = res + 1;
    }
};

/*---------------数据结构---------------*/

// ST表 , 求区间最大,最小值, 区间gcd, lcm
// 预处理 O(nlogn), 查询 O(1) 
class ST {
    int min_arr[N][17];  // 最小值
    int max_arr[N][17];  // 最大值
    int gcd_arr[N][17];  // 区间GCD
    int lcm_arr[N][17];  // 区间LCM
    int log_2[N+1]; // 预计算 log2
    // 预处理：构建 ST 表
    void buildST(const vector<int>& arr) {
        int n = arr.size();
        // 初始化 log_2
        log_2[1] = 0;
        for (int i = 2; i <= n; ++i) {
            log_2[i] = log_2[i / 2] + 1;
        }
        // 初始化 ST 表的第一列
        for (int i = 0; i < n; ++i) {
            max_arr[i][0] = arr[i];
            min_arr[i][0] = arr[i];
            gcd_arr[i][0] = arr[i];
            lcm_arr[i][0] = arr[i];
        }
        // 填充 ST 表
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                max_arr[i][j] = max(max_arr[i][j - 1], max_arr[i + (1 << (j - 1))][j - 1]);
                min_arr[i][j] = min(min_arr[i][j - 1], min_arr[i + (1 << (j - 1))][j - 1]);
                gcd_arr[i][j] = gcd(gcd_arr[i][j - 1], gcd_arr[i + (1 << (j - 1))][j - 1]);
                lcm_arr[i][j] = lcm(lcm_arr[i][j - 1], lcm_arr[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    // 查询区间 [L, R] 的最大值
    int query_max(int L, int R) {
        int len = R - L + 1;
        int j = log_2[len];
        return max(max_arr[L][j], max_arr[R - (1 << j) + 1][j]);
    }
    // 查询区间 [L, R] 的最小值
    int query_min(int L, int R) {
        int len = R - L + 1;
        int j = log_2[len];
        return min(min_arr[L][j], min_arr[R - (1 << j) + 1][j]);
    }
    // 查询区间 [L, R] 的gcd
    int query_gcd(int L, int R) {
        int len = R - L + 1;
        int j = log_2[len];
        return gcd(gcd_arr[L][j], gcd_arr[R - (1 << j) + 1][j]);
    }
    // 查询区间 [L, R] 的lcm
    int query_lcm(int L, int R) {
        int len = R - L + 1;
        int j = log_2[len]; 
        return lcm(lcm_arr[L][j], lcm_arr[R - (1 << j) + 1][j]);
    }
};

// 并查集 接近O(1)
class DSU {
    int par[N], rk[N];
    // 初始化n个元素
public:
    void init(int n) {
        for(int i = 1;i <= n;++i) par[i] = i;
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

// 树状数组
class FenwickTree {
    int n,m;
    int a[N],c[N];
    // 求最低为 1的位置
    int lowbit(int x) { return x&(-x); }
    int sum(int x) {
        int res = 0;
        for(int i = x; i; i -= lowbit(i)) res += c[i];
        return res;
    }
    void add(int x, int y) {
        for(int i = x; i <= n; i += lowbit(i)) c[i] += y;
    }
};

// 线段树
class SegmentTree {
    #define lc p<<1
    #define rc p<<1|1
    int n, w[N];
    // 树的结点 
    struct node {
        int l, r, sum, add; 
    }tr[N*4];
    // 向上更新
    void pushup(int p) {
        tr[p].sum = tr[lc].sum + tr[rc].sum;
    }
    // 向下更新
    void pushdown(int p) {
        if(tr[p].add) {
            tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
            tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
            tr[lc].add += tr[p].add;
            tr[rc].add += tr[p].add;
            tr[p].add = 0;
        }
    }
    // 建树 build(根结点,左子树,右子树)
    void build(int p, int l, int r) {
        tr[p] = {l, r, w[l],0};
        if(l == r) return;
        int m = l + r >> 1;
        build(lc, l, m);
        build(rc, m + 1, r);
        pushup(p);
    }
    // 区间修改 
    void update(int p, int x, int y, int k) {
        if(x<=tr[p].l && tr[p].r<=y) {
            tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
            tr[p].add += k;
            return;
        }
        int m = tr[p].l + tr[p].r >> 1;
        pushdown(p);
        if(x <= m) update(lc, x, y, k);
        if(y > m) update(rc, x, y, k);
        pushup(p);
    }
    // 区间查询
    int query(int p, int x, int y) {
        if(x <= tr[p].l && tr[p].r <= y) return tr[p].sum;
        int m = tr[p].l + tr[p].r >> 1;
        pushdown(p);
        int sum = 0;
        if(x <= m) sum += query(lc, x, y);
        if(y > m) sum += query(rc, x, y);
        return sum;
    }
};

/*---------------图论---------------*/

// 最短路 dijkstra算法(优先队列优化版) O(mlogn)
class _dijkstra_ {
    struct edge{   
        int v,w; // v:点 , w:权
    };
    int pre[N];// 记录路径
    int n, m; // n个点, m条边
    int d[N], vis[N];  // d[N]存个点到原点最小距离, vis[N]标记是否出圈
    vector<edge> G[N]; // 创建图
    // dijkstra(s), s为起始点 
    void dijkstra(int s) {
        fill(d, d + n + 1, inf);
        d[s] = 0;
        // 边取负, 故用大根堆
        priority_queue<pair<int, int>> q;  
        q.push({0, s});
        while(!q.empty()) {
            auto t = q.top();q.pop();
            int u = t.second;
            if(vis[u]) continue;
            vis[u] = 1;
            // 松弛操作
            for(auto e : G[u]) {
                int v = e.v, w = e.w;
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pre[v] = u;
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
        dfs_path(pre[u], s);
        cout << u << ' ';
    }
};

// 最小生成树MST kruskal算法 
class MST {
private:
    struct edge{
        int u, v, cost;
        bool operator<(const edge& other) const {
            return cost < other.cost; // 按权值升序排序
        }
    };
    DSU dsu; // 并查集成员函数
    vector<edge> es; // 边集
    vector<edge> mst; //最小生成树边集
    int V, res; //V:点数 res:MST各边长之和
public:
    MST(int n) : V(n) {} // 构造函数, 赋值V为n
    int kruskal() {
        sort(es.begin(), es.end());
        dsu.init(V);
        mst.clear();
        res =  0;
        for(auto &e : es) {
            if(!dsu.same(e.u, e.v)) {
                dsu.unite(e.u, e.v);
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
    // 判断是否连通, 先要使用kruskal(),不然并查集没有元素
    bool isConnected() {
        set<int> st;
        for (int i = 1; i <= V; ++i) {
            st.insert(dsu.find(i));
        }
        return st.size() == 1;
    }
};
// 最近公共祖先 LCA
class LCA {
private:
    static const int LOG = 17;
public:
    vector<int> G[N];    // 邻接表表示树
    int par[N][LOG];     // parent[u][i]表示u的2^i祖先
    int dep[N];          // 深度数组
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
void solve() {

    cout << "Hello C++!" << endl;

}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}