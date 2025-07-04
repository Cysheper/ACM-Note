#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
#define ls u << 1
#define rs u << 1 | 1
#define N 500005
struct line {
    int x1, x2, y;
    int tag;
    bool operator<(line &t) {
        return y < t.y;
    }
}L[N];
struct tree {
    int l, r;
    int cnt, len;
}tr[N * 8];
int X[N];

void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}




void solve() {
    

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