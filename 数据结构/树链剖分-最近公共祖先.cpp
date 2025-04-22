/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 5e5 + 5; 
vector<int> G[N];
int fa[N], dep[N], son[N], sz[N];
int top[N];
void dfs1(int u, int father) {
    fa[u] = father,dep[u] = dep[father] + 1,sz[u] = 1;
    for(auto v : G[u]) {
        if(v == father) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(auto v : G[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}   
int lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
void solve(){
    int n, m, s; cin >> n >> m >> s;
    for(int i=0;i<n-1;++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(s, 0);
    dfs2(s ,s);
    for(int i=0;i<m;++i) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}