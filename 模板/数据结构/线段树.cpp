/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll 
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
void pushdown(int p) {
    if(tr[p].add) {
        tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
        tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
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
void update(int p, int x, int y, int k) {
    if(x <= tr[p].l && tr[p].r <= y) {
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        tr[p].add += k;
        return;
    }
    int m = (tr[p].l + tr[p].r) >> 1;
    pushdown(p);
    if(x <= m) update(lc, x, y, k);
    if(y > m) update(rc, x, y, k);
    pushup(p);
}
// 区间查询
int query(int p, int x, int y) {
    if(x <= tr[p].l && tr[p].r <= y) return tr[p].sum;
    int m = (tr[p].l + tr[p].r) >> 1;
    pushdown(p);
    int sum = 0;
    if(x <= m) sum += query(lc, x, y);
    if(y > m) sum += query(rc, x, y);
    return sum;
}
// 单点修改
void update(int p, int x, int k) {
    if(tr[p].l == x && tr[p].r == x) {
        tr[p].sum = k;
        return;
    }
    int m = (tr[p].l + tr[p].r) >> 1;
    if(x <= m) update(lc, x, k);
    if(x > m)  update(rc, x, k);
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}
// 单点查询
int get(int x) {
    return query(1, x, x);  // 查询区间 [x, x] 的值
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n; ++ i) {
        cin >> w[i];
    }
    build(1, 1, n);
    while(m --) {
        int c, a, b, d;
        cin >> c >> a >> b;
        if(c == 1) {
            cin >> d;
            update(1, a, b, d);
        } else {
            cout << query(1, a, b) << '\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}