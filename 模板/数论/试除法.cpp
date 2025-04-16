/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= n / i;++i) {
        if (n % i == 0) {
            st.insert(i);
            if (i != n / i) {
                st.insert(n / i);
            }
        }
    }
    if(k > st.size()) {
        cout << -1 << "\n";
    }
    else {
        auto it = st.begin();
        advance(it, k - 1);
        cout << *it << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}