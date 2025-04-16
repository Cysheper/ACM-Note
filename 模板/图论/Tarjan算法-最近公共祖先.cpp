/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 5e5 + 5;
vector<int> G[N];
vector<pair<int,int>> q[N];
int fa[N], vis[N], ans[N];
int find(int x) {
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}
void tarjan(int u) {
    vis[u] = true;
    for(auto v : G[u]) {
        if(!vis[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for(auto qu : q[u]) {
        int v = qu.first, i = qu.second;
        if(vis[v]) ans[i] = find(v);
    }
}
void solve(){
    int n, m, s; cin >> n >> m >> s;
    for(int i=0;i<n-1;++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<m;++i) {
        int a, b; cin >> a >> b;
        q[a].push_back({b, i});
        q[b].push_back({a, i});
    }
    for(int i=1;i<=n;++i) fa[i] = i;
    tarjan(s);
    for(int i=0;i<m;++i) {
        cout << ans[i] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}