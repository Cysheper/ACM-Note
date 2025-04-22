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
const int N = 1e5 + 5;
vector<int> e[N];
int ans = 0, poi = 0;
int vis[N];
void dfs(int x, int dep) {
    vis[x] = 1;
    for(auto v : e[x]) {
        if(!vis[v]) dfs(v, dep+1);
    }
    if(dep > ans) {
        ans = dep;
        poi = x;
    }
}
void solve() {
    int n; cin >> n;
    int a, b;
    for(int i=0;i<n-1;++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 1);
    memset(vis, 0, sizeof(vis));
    dfs(poi, 1);
    cout << ans-1;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}