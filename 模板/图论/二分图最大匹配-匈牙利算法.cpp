/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define inf 0x3f3f3f3f
#define eps 1e-19
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// 二分图最大匹配-匈牙利算法
int n, m, k, ans;
const int M = 1005, N = 1e5 + 5;
struct edge {
    int v, ne; // 终点,边权,下一条边
}e[N]; // 边集
int idx, h[N];
int vis[N], match[N];
// 记得加 memset(h, -1, sizeof(h)); 
// 带权添加
void add(int a, int b) {
    e[++idx] = {b, h[a]};
    h[a] = idx;
}
bool dfs(int u) {
    for(int i=h[u];i;i=e[i].ne) {
        int v = e[i].v;
        if(vis[v]) continue;
        vis[v] = 1;
        if(!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m >> k;
    int a, b;
    for(int i=0;i<k;++i) {
        cin >> a >> b;
        add(a, b);
    }
    for(int i=1;i<=n;++i) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) ans++;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}