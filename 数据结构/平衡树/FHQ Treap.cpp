#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
#define N 5100010
// FHQ Treap
struct node {
    int l, r;
    int v;
    int key;
    int sz;
}tr[N];
int n, root, idx;

int newNode(int v) {
    tr[++idx].v = v;
    tr[idx].key = rand();
    tr[idx].sz = 1;
    return idx;
}

void pushup(int p) {
    tr[p].sz =
        tr[tr[p].l].sz +
        tr[tr[p].r].sz + 1;
}

void split(int p, int v, int &x, int &y) {
    if(!p) { x = y = 0; return; } 
    if(tr[p].v <= v) {
        x = p;
        split(tr[x].r, v, tr[x].r, y);
    } else {
        y = p;
        split(tr[y].l, v, x, tr[y].l);
    }
    pushup(p);
}

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(tr[x].key < tr[y].key) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x); return x;
    } else {
        tr[y].l = merge(x, tr[y].l);
        pushup(y); return y;
    }
}

void insert(int v) {
    int x, y, z;
    split(root, v, x, y);
    z = newNode(v);
    root = merge(merge(x, z), y);
}

void del(int v) {
    int x, y, z;
    split(root, v, x, z);
    split(x, v - 1, x, y);
    y = merge(tr[y].l, tr[y].r);
    root = merge(merge(x, y), z);
}

int get_k(int p, int k) {
    if(k <= tr[tr[p].l].sz) 
        return get_k(tr[p].l, k);
    if(k == tr[tr[p].l].sz + 1)
        return p;
    return get_k(tr[p].r, k - tr[tr[p].l].sz - 1);
}

int get_pre(int v) {
    int x, y;
    split(root, v - 1, x, y);
    int p = get_k(x, tr[x].sz);
    return tr[p].v;
    root = merge(x, y);
}

int get_suc(int v) {
    int x, y;
    split(root, v, x, y);
    int p = get_k(y, 1);
    return tr[p].v;
    root = merge(x, y);
}

int get_rk(int v) {
    int x, y;
    split(root, v - 1, x, y);
    return tr[x].sz + 1;
    root = merge(x, y);
}

int get_val(int k) {
    int p = get_k(root, k);
    return tr[p].v;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++ i) {
        int x; cin >> x;
        insert(x);
    }
    int last = 0, res = 0, ans = 0;
    while(m --) {
        int op, x;
        cin >> op >> x;
        x ^= last;
        if(op==1) insert(x);
        if(op==2) del(x);
        if(op==3) res ^= (last = get_rk(x));
        if(op==4) res ^= (last = get_val(x));
        if(op==5) res ^= (last = get_pre(x));
        if(op==6) res ^= (last = get_suc(x));
    }
    cout << res << "\n";

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