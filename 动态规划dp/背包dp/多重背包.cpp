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
// 牛客竞赛 【模板】多重背包


// 二进制优化
void solve() {
    vi vv, ww;  // 存体积， 存价值
    int n, m; cin >> n >> m; // 种数， 总体积
    int v, w, s; //体积， 价值， 数量
    for (int i = 1; i <= n; ++ i) {
        cin >> v >> w >> s;
        for (int j = 1; j <= s; j <<= 1) {
            vv.pb(j * v);
            ww.pb(j * w);
            s -= j;
        }
        if (s) {
            vv.pb(s * v);
            ww.pb(s * w);
        }
    }    
    // 01背包
    vi dp(m + 1);
    for (int i = 0; i < sz(vv); ++ i) {
        for (int j = m; j >= vv[i]; -- j) {
            dp[j] = max(dp[j], dp[j-vv[i]] + ww[i]);
        }
    }
    cout << dp[m];
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}