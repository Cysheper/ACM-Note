#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s = "12345678";
string ed = "";
queue<string> q;
map<string, string> mp;

void A(string x) {
    string y = x;
    for(int i = 0; i < 4; ++ i) swap(x[i], x[7-i]);
    if(mp.count(x) == 0) {
        q.push(x);
        mp[x] = mp[y] + 'A';
    }
}
void B(string x) {
    string y = x;
    x[0] = y[3], x[1] = y[0], x[2] = y[1], x[3] = y[2];
    x[4] = y[5], x[5] = y[6], x[6] = y[7], x[7] = y[4];
    if(mp.count(x) == 0) {
        q.push(x);
        mp[x] = mp[y] + 'B';
    }
}
void C(string x) {
    string y = x;
    x[1] = y[6], x[2] = y[1], x[5] = y[2], x[6] = y[5];
    if(mp.count(x) == 0) {
        q.push(x);
        mp[x] = mp[y] + 'C';
    }
}
void bfs(string s) {
    q.push(s); mp[s] = "";
    while(q.size()) {
        string s = q.front(); q.pop();
        A(s); B(s); C(s);
        if(mp.count(ed)) {
            cout << mp[ed].size() << "\n" << mp[ed];
            return;
        }
    }
}

void solve() {
    for(int i = 0; i < 8; ++ i) {
        char c; cin >> c;
        ed += c;
    }
    bfs(s);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}