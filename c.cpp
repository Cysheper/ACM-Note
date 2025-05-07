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
#define lower(a, x) lower_bound(all(a), x) - a.begin()
#define upper(a, x) upper_bound(all(a), x) - a.begin()
#define debug(x) cerr << #x << " = " << x << endl
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define A cout << "Alice\n"
#define B cout << "Bob\n"
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
const int p = 1e9 + 7;
const int mod = 998244353;
/*===================================== TEMPLATE =====================================*/
// 快读
inline void read(int &num) {
    char c = getchar();
    int k = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = k * 10 + c - '0';
        c = getchar();
    }
    num = k * f;
}
// 快速幂
inline int quick_pow(int x, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
// gcd(a, b) 求a, b最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// lcm(a, b) 求a, b最小公倍数
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
// 欧拉筛 O(n)
inline vector<int> ola(int n) {
    vector<int> prime;
    prime.reserve(n / 10); 
    vector<char> vis(n + 5);
    prime.pb(2);
    for (int i = 3; i <= n; i += 2) { // 排除所有除了2的偶数
        if (!vis[i]) prime.pb(i);
        for (int j = 0; i * prime[j] <= n; ++ j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime;
}
// 试除法求第k个约数 O(sqrt(n))
inline int trial(int n, int k) {
    set<int> st;// 存放n的约数
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            st.insert(i);
            st.insert(n / i);
        }
    }
    if(k > st.size()) return -1;
    else {
        auto it = st.begin();
        advance(it, k - 1);
        return *it;
    }
}
// 并查集 接近O(1)
struct DSU {
    vector<int> par, rk;
    DSU(int n) {
        par.resize(n + 1);
        rk.resize(n + 1, 1); // 初始每个集合的秩为 1
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    bool unite(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (rk[fx] < rk[fy]) swap(fx, fy);
        par[fy] = fx;
        if (rk[fx] == rk[fy]) rk[fx]++;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
/*===================================== BEGIN =====================================*/
void solve() {
    int n;
    cin >> n;
    for (int l = 0; l <= 9; l++) {
        string s = to_string(n - l);
        int md = 0;
        for (auto c: s) {
            if (c <= '7') {
                md = max(md, int(c - '0'));
            }
        }
        if (l >= 7 - md) {
            cout << l << '\n';
            return;
        }
    }
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