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
typedef vector<pii> vii;
const int p = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(m + 1, 0), v(m + 1, 0);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++ i) 
        cin >> w[i] >> v[i];
    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            if (j < w[i]) 
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[m][n] << "\n";
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