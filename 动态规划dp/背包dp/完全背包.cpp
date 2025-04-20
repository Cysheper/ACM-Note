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
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int p = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;
// 洛谷 P1616 疯狂的采药

// 二维dp
void solve() {
    int n, m; cin >> n >> m; // 采药时间和草药种数    
    vi t(m + 1), v(m + 1); // 每株草药的采集时间和价值
    vvi dp(m + 1, vi(n + 1)); // dp数组
    for(int i = 1; i <= m; ++ i) {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (j < t[i]) 
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-t[i]] + v[i]);
        }
    }
    cout << dp[m][n];
}

// 一维dp
void solve2() {
    int n, m;
    cin >> n >> m;
    vi t(m + 1), v(m + 1);
    for (int i = 1; i <= m; ++ i) {
        cin >> t[i] >> v[i];
    }
    vi dp(n + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++ j) {
            if(j >= t[i])
                dp[j] = max(dp[j], dp[j-t[i]] + v[i]);
        }
    }
    cout << dp[n];
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while(_--) solve2();
    return 0;
}