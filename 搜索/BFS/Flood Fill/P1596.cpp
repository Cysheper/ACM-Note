/* author: Cysheper */
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define inf 0x3f3f3f3f
#define eps 1e-19
#define int ll
#define pb push_back
#define x first
#define y second
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define fill(a, b) fill(all(a), b)
#define lowbit(x) ((x) & -(x))
#define debug(x) cerr << #x << " = " << x << endl
#define Y cout << "YES\n"
#define N cout << "NO\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vb> vvb;
const int p = 1e9 + 7;
const int mod = 998244353;
// P1596 [USACO10OCT] Lake Counting S
int n, m; 
void bfs(int x, int y, vs &v, vvb &st) {
    queue<pii> q;
    q.push({x, y});
    st[x][y] = true;
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = t.x - 1; i <= t.x + 1; ++ i) 
            for (int j = t.y - 1; j <= t.y + 1; ++ j) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || j < 0 || i >= n || j >= m) continue;
                if (v[i][j] == '.' || st[i][j]) continue;
                q.push({i, j});
                st[i][j] = true;
            }
    }
}
void solve() {
    cin >> n >> m;
    vs v(n);
    vvb st(n, vb(m, false));
    for (auto &s: v) cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++ i) 
        for (int j = 0; j < m; ++ j) {
            if (v[i][j] == 'W' && !st[i][j]) {
                bfs(i, j, v, st);
                cnt ++;
                st[i][j] = true;
            }
        }
    cout << cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}