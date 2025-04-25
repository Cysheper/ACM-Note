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

// 矩阵
struct matrix {
    ll c[101][101];
    matrix() {memset(c, 0, sizeof(c));}
} A, res; // A: 原矩阵， res: 结果矩阵
ll n, k;  // n 阶矩阵， k 阶幂

// 矩阵乘法
matrix operator*(matrix &x, matrix &y) {
    matrix t; // 临时矩阵
    for (int i = 1; i <= n; ++ i) 
        for (int j = 1; j <= n; ++ j) 
            for (int k = 1; k <= n; ++ k) 
                t.c[i][j] = (t.c[i][j] + x.c[i][k]*y.c[k][j]) % p;
    return t;
}

// 快速幂
void quickpow(ll k) {
    for (int i = 1; i <= n; ++ i) res.c[i][i] = 1; // 单位矩阵
    while(k) {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cin >> A.c[i][j];
        }
    }
    quickpow(k);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cout << res.c[i][j] << " \n"[j == n];
        }
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