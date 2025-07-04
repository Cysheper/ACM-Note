#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
template<int N>
struct Trie01 {
    vector<vector<int>> ch;
    int idx;

    Trie01() {
        ch.resize(N * 31, vector<int>(2, 0));
        idx = 0;
    }

    void insert(int x) {
        int p = 0;
        for(int i = 30; i >= 0; -- i) {
            int j = x >> i & 1;
            if(!ch[p][j]) ch[p][j] = ++idx;
            p = ch[p][j];
        }
    }

    int query(int x) {
        int p = 0, res = 0;
        for(int i = 30; i >= 0; -- i) {
            int j = x >> i & 1;
            if(ch[p][!j]) {
                res += 1 << i;
                p = ch[p][!j];   
            } else p = ch[p][j];
        }
        return res;
    }

};

void solve() {
    int n; cin >> n;
    const int N = 100005;
    Trie01<N> trie;
    int ans = 0;
    vector<int> v(n);
    for(int i = 0; i < n; ++ i) {
        cin >> v[i];
        trie.insert(v[i]);
    }
    for(int i = 0; i < n; ++ i) {
        ans = max(ans, trie.query(v[i]));
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1; 
    // cin >> _;
    while(_ --) solve();
    return 0;
}