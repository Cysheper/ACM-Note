/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define inf 0x3f3f3f3f
#define eps 1e-19
#define int ll
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define fill(a, b) fill(all(a), b)
#define lowbit(x) ((x) & -(x))
#define debug(x) cerr << #x << " = " << x << endl
#define Yes cout << "Yes\n"
#define No cout << "No\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vii;
const int p = 1e9 + 7;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int cnt = (n * m) / k;
    vvi v(n, vi(m));
    int num = 1;
    int idx = 0;
    if (k == n && k == m) {
        int pos = 0;
        for (int i = 0; i < n; ++ i) {
            num = 1;
            for (int j = pos; j < m; ++ j) {
                v[i][j] = num;
                num ++;
            }
            for (int j = 0; j < pos; ++ j) {
                v[i][j] = num;
                num ++;
            }
            pos ++;
        }
        for(auto i: v) {
            for(auto j: i) {
                cout << j << " ";
            }
            cout << "\n";
        }
        return;
    }
    if (k % n == 0) {
        swap(n, m);
    }
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            idx ++;
            v[j][i] = num;
            num ++;
            if (num == k + 1) {
                num = 1;
            }
        }
    }
    for(auto i: v) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "\n";
    }
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