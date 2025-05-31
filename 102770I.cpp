/* author: Cysheper */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int ll
#define pb push_back
#define x first
#define y second
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof a)
#define fill(a, b) fill(all(a), b)
#define lowbit(x) ((x) & -(x))
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define lowb(a, x) lower_bound(all(a), x) - a.begin()
#define upb(a, x)  upper_bound(all(a), x) - a.begin()
#define debug(x) cerr << #x << " = " << x << endl
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Alice cout << "Alice\n"
#define Bob cout << "Bob\n"
typedef pair<int, int> pii;
typedef pair<char,char> pcc;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vb> vvb;
/*===================================== TEMPLATE =====================================*/
int quick_pow(int x, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

const int p = 1e9 + 7;
const int mod = 998244353;

/*===================================== BEGIN =====================================*/
map<int, vector<int>> G;
map<int, bool> vis;
int ans = 0;
void dfs(int x) {
    vis[x] = 1;
    ans ++;
    for(int i: G[x]) {
        if(!vis[i])
        dfs(i);
    }
}

void solve() {
    int n; cin >> n;
    vi num;
    map<int, int> mp;
    for(int i = 0; i < n; ++ i) {
        int u, v; cin >> u >> v;
        num.pb(u);
        num.pb(v);
        G[u].pb(v);
    }
    int res = 0;
    for(int i = 0; i < sz(num); ++ i) {
        if(!vis[num[i]]) {
            ans = 0;
            dfs(num[i]);
            res = max(res, ans);
        }
    }
    cout << res << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    cin >> _;
    while(_ --) solve();
    
    return 0;
}