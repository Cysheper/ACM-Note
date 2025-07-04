#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define lc p<<1
#define rc p<<1|1
#define N 100005
int n, w[N];
// 树的结点 
struct node {
    int l, r, sum, add; 
}tr[N*4];
// 向上更新
void pushup(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}
// 向下更新
void pushdown(int p, int len) {
    if(tr[p].add) {
        tr[lc].sum = (len - (len >> 1)) - tr[lc].sum;
        tr[rc].sum = (len >> 1) - tr[rc].sum;
        tr[lc].add ^= 1;
        tr[rc].add ^= 1;
        tr[p].add = 0;
    }
}
// 建树 build(根结点,左子树,右子树)
void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if(l == r) return;
    int m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    pushup(p);
}
// 区间修改 
void update(int p, int x, int y) {
    if(x <= tr[p].l && tr[p].r <= y) {
        tr[p].sum = y - x + 1 - tr[p].sum;
        tr[p].add ^= 1;
        return;
    }
    int m = (tr[p].l + tr[p].r) >> 1;
    pushdown(p, y - x + 1);
    if(x <= m) update(lc, x, y);
    if(y > m) update(rc, x, y);
    pushup(p);
}
// 区间查询
int query(int p, int x, int y) {
    if(x <= tr[p].l && tr[p].r <= y) return tr[p].sum;
    int m = (tr[p].l + tr[p].r) >> 1;
    pushdown(p, y - x + 1);
    int sum = 0;
    if(x <= m) sum += query(lc, x, y);
    if(y > m) sum += query(rc, x, y);
    return sum;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for(int i = 0; i < n; ++ i) {
        if(s[i] == '1') {
            w[i + 1] = 1;
        } else w[i + 1] = 0;
    }
    
    build(1, 1, n + 1);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 0) {
            update(1, l, r);
        } else {
            cout << query(1, l, r) << "\n";
        }
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