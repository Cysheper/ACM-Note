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
const int N = 5e4 + 5;
vector<int> G[N];
int vis[N], d[N];
int ans = 0;
int maxx = INT_MAX;
int n; 
void dfs(int x,int par) {
    int res = 0;
    d[x] = 1;
    for(auto u : G[x]) {
        if(u == par) continue; 
        dfs(u, x);
        d[x] += d[u];
        res = max(res, d[u]);
    }
    res = max(res, n - d[x]);
    if(res < maxx || (res == maxx && ans > x)) {
        maxx = res;
        ans = x;
    }
} 
void solve() {
    

}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}