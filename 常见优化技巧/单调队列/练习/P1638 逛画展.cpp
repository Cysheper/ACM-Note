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
// #define int ll
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
// 洛谷 P1638
void solve() {
    int n, k; cin >> n >> k;
    vi v(n);
    for (auto &i: v) cin >> i;
    deque<int> dq;
    map<int, int> mp;
    int l = 0, r = 0, len = INT_MAX;
    for (int i = 0; i < n; ++ i) {
        if (sz(mp) < k) {
            mp[v[i]] ++;
            dq.push_back(i);    
        }
        if (sz(mp) == k) {
            while(mp[v[dq.front()]] > 1) {
                mp[v[dq.front()]] --;
                dq.pop_front();
            }
            if (len > i - dq.front()) {
                len = i - dq.front();
                l = dq.front();
                r = i;
            }
            if (mp[v[dq.front()]] != 1) mp[v[dq.front()]] --;
            else mp.erase(v[dq.front()]);
            dq.pop_front();
        }
    }
    cout << l + 1 << " " << r + 1;
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