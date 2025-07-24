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
#define Yes cout << "Yes\n"
#define No cout << "No\n"
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


void solve() {
    int n, m; cin >> n >> m;
    vi v(n);
    for(int &i: v) cin >> i;


    int l = *max_element(all(v));
    int r = accumulate(all(v), 0);

    auto check = [&](int x) -> bool {
        int sum = 0, cnt = 1;
        for(int i = 0; i < n; ++ i) {
            if(sum + v[i] <= x) {
                sum += v[i];
            } else {
                sum = v[i];
                cnt ++;
            }
        }
        return cnt <= m;
    };  
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    while(_ --) solve();
    
    return 0;
}