#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
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

    int query(string s) {
        int p = 0;
        for(int i: s) {
            int j = i - 'a';
            if(!ch[p][j]) return 0; 
            p = ch[p][j];
        }
        return cnt[p];
    }
};

void solve() {
    int n; cin >> n;
    const int N = 5e3 + 5;
    vector<Trie<N>> v(n);
    for(int i = 0; i < n; ++ i) {
        int num; cin >> num;
        string s;
        while(num --) {
            cin >> s;
            v[i].insert(s);
        }
    }
    string s;
    int m; cin >> m;
    while(m --) {
        cin >> s;
        vector<int> ans;
        for(int i = 0; i < n; ++ i) {
            if(v[i].query(s)) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(int i: ans) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
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