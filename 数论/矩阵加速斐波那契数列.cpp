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
    ll c[3][3];
    matrix() {memset(c, 0, sizeof(c));}
} F, A; //F为斐波那契矩阵，A为构造矩阵
/*
A = [1 1]
    [1 0]
*/
// 矩阵乘法
matrix operator*(matrix &x, matrix &y) {
    matrix t; // 临时矩阵
    for (int i = 1; i <= 2; ++ i) 
        for (int j = 1; j <= 2; ++ j) 
            for (int k = 1; k <= 2; ++ k) 
                t.c[i][j] = (t.c[i][j] + x.c[i][k]*y.c[k][j]) % p;
    return t;
}

// 快速幂
void quickpow(ll n) {
    F.c[1][1] = F.c[1][2] = 1;
    A.c[1][1] = A.c[1][2] = A.c[2][1] = 1;
    while(n) {
        if (n & 1) F = F * A;
        A = A * A;
        n >>= 1;
    }
}
void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) cout << 1;
    else {
        quickpow(n - 2); // 一定要n - 2
        cout << F.c[1][1];
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