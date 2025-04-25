/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define inf 0x3f3f3f3f
#define eps 1e-19
#define int ll
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define fill(a, b) fill(all(a), b)
#define debug(x) cerr << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vii;
const int p = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;
void dfs(int u, vvi&dp, vi&w, vvi&G) {
    dp[u][1] = w[u];
    for (int i = 0; i < sz(G[u]); ++ i) {
        int son = G[u][i];
        dfs(son, dp, w, G);
        dp[u][0] += max(dp[son][0], dp[son][1]);
        dp[u][1] += dp[son][0];
    }
}

void solve() {
    int n; cin >> n;
    vi w(n + 1), fa(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> w[i];
    vvi G(n + 1), dp(n + 1, vi(3));
    for (int i = 0; i < n - 1; ++ i) {
        int x, y; cin >> x >> y;
        G[y].push_back(x);
        fa[x] = 1;
    }
    int root = 1;
    while(fa[root]) root ++;
    dfs(root, dp, w, G);
    cout << max(dp[root][0], dp[root][1]);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}