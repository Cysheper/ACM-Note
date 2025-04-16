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
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++ i) {
        cin >> v[i];
    }
    vector<int> dp(n, 1);
    int ans = 0;
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < i; ++ j) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans;
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