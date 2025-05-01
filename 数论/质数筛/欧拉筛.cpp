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
const int N = 1e8 + 5;
// 时间复杂度: O(n)
vector<int> ola(int n) {
    vector<int> prime;
    prime.reserve(n / 10); 
    vector<char> vis(n + 1);
    prime.pb(2);
    for (int i = 3; i <= n; i += 2) {
        if (!vis[i]) prime.pb(i);
        for (int j = 0; i * prime[j] <= n; ++ j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v = ola(n);
    while(q--) {
        int x; cin >> x;
        cout << v[x-1] << "\n";
    }
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