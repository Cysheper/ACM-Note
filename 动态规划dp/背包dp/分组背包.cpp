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

void solve() {
    int n, V; cin >> n >> V;
    vi v(int(2e5)), w(int(2e5));
    int s;
    vi dp(V + 1);
    for (int i = 1; i <= n; ++ i) {
        cin >> s;
        for (int j = 1; j <= s; -- j) {
            cin >> v[j] >> w[j];
        }
        for (int j = V; j >= 1; --j) {
            for (int k = 0; k <= s; ++ k) {
                if (j >= v[k]) {
                    dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
                }
            }
        }
    }
    cout << dp[V] << "\n";
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