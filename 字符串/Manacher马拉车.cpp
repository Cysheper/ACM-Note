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
const int N = 2e7 + 5;
char a[N];
char s[N << 1];
int d[N << 1];
// scanf("%s", a + 1);
int manacher(char *a) {
    int n = strlen(a + 1), k = 0;
    s[0] = '$', s[++k] = '#';
    for(int i = 1; i <= n; ++ i) {
        s[++k] = a[i];
        s[++k] = '#';
    }
    n = k, d[1] = 1;
    for(int i = 2, l, r = 1; i <= n; ++ i) {
        if(i <= r) d[i] = min(d[r-i+l], r-i+1);
        while(s[i-d[i]] == s[i+d[i]]) d[i]++;
        if(i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }
    return *max_element(d, d + n) - 1;
}

void solve() {  
    scanf("%s", a+1);
    cout << manacher(a);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}