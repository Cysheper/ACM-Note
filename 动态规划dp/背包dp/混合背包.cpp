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
    int n, m; cin >> n >> m;
    vi a, b, c;
    int v, w, s;
    for (int i = 1; i <= n; ++ i) {
        cin >> v >> w >> s;
        if (s == 0) {
            a.pb(v);
            b.pb(w);
            c.pb(0);
        } else {
            if (s == -1) s = 1;
            int k = 1;
            while (s >= k) {
                a.pb(k * w);
                b.pb(k * w);
                c.pb(1);
                s -= k;
                k <<= 1;
            } if(s) {
                a.pb(s * v);
                b.pb(s * w);
                c.pb(1);
            }
        }
    }
    vi dp(m);
    for (int i = 1; i < sz(c); ++ i) {
        if (c[i] == 1) 
            for (int j = m; j >= a[i]; -- j) 
                dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
        else 
            for (int j = a[i]; j <= m; ++ j)
                dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
    }
    cout << dp[m] << "\n";
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