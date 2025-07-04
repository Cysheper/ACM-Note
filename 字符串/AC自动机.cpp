#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll、
template<int N>
struct Trie {
    vector<vector<int>> ch;
    vector<int> cnt;
    int idx;

    Trie() {
        ch.assign(N, vector<int>(26, 0));
        cnt.assign(N, 0);
        idx = 0;
    }

    void insert(string s) {
        int p = 0;
        for(int i: s) {
            int j = i - 'a';
            if(!ch[p][j]) ch[p][j] = ++idx;
            p = ch[p][j];
        }
        cnt[p] ++;
    } 
};
template<int N>
struct AC: Trie<N> {
    vector<int> ne;

    AC() {
        ne.resize(N);
    }
      
    void build() {
        queue<int> q;
        for(int i = 0; i < 26; ++ i) 
            q.push(this->ch[0][i]);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < 26; ++ i) {
                int v = this->ch[u][i];
                if(v) {
                    this->ne[v] = this->ch[this->ne[u]][i];
                    q.push(v);
                } else this->ch[u][i] = this->ch[this->ne[u]][i];
            }
        }
    }

    int query(string s) {
        int ans = 0, i = 0;
        for(int k: s) {
            i = this->ch[i][k - 'a'];
            for(int j = i; j && ~this->cnt[j]; j = this->ne[j]) {
                ans += this->cnt[j];
                this->cnt[j] = -1;
            }
        }
        return ans;
    }
}; 



void solve() {
    int n; cin >> n;
    string s;
    AC<1000005> ac;
    for(int i = 0; i < n; ++ i) {
        cin >> s;
        ac.insert(s);
    }
    string ss; cin >> ss;
    cout << ac.query(ss);
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