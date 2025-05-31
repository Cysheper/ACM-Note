#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
#define N 1100010
#define inf INT_MAX
struct node{
    int s[2]; // 左右儿子
    int p; // 父亲
    int v; // 节点值
    int cnt; // 值出现的个数
    int sz; // 子树大小
    
    void init(int pp, int vv) {
        p = pp, v = vv;
        cnt = sz = 1;
        s[0] = s[1] = 0;
    }
}tr[N];
int root; // 根节点编号
int idx; // 节点个数

void pushup(int x) {
    tr[x].sz = tr[tr[x].s[0]].sz + 
               tr[tr[x].s[1]].sz + 
               tr[x].cnt;
}

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[y].s[k] = tr[x].s[k ^ 1];
    tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y;
    tr[y].p = x;
    tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    pushup(y); pushup(x);
}

void splay(int x, int k) {
    while(tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if(z != k) 
            (tr[y].s[0] == x) ^ (tr[z].s[0] == y)
            ? rotate(x) : rotate(y);
        rotate(x);
    }
    if(!k) root = x;
}

void insert(int v) {
    int x = root, p = 0;
    while(x && tr[x].v != v) {
        p = x;
        x = tr[x].s[v > tr[x].v];
    }
    if(x) tr[x].cnt ++;
    else {
        x = ++idx;
        tr[p].s[v > tr[p].v] = x;
        tr[x].init(p, v);
    }
    splay(x, 0);
}

void find(int v) {
    int x = root;
    while(tr[x].s[v > tr[x].v] && v != tr[x].v) 
        x = tr[x].s[v > tr[x].v];
    splay(x, 0);
}

int get_pre(int v) {
    find(v);
    int x = root;
    if(tr[x].v < v) return x;
    x = tr[x].s[0];
    while(tr[x].s[1]) x = tr[x].s[1];
    splay(x, 0);
    return x;
}

int get_suc(int v) {
    find(v);
    int x = root;
    if(tr[x].v > v) return x;
    x = tr[x].s[1];
    while(tr[x].s[0]) x = tr[x].s[0];
    splay(x, 0);
    return x;
}

void del(int v) {
    int pre = get_pre(v);
    int suc = get_suc(v);
    splay(pre, 0); splay(suc, pre);
    int del = tr[suc].s[0];
    if(tr[del].cnt > 1) 
        tr[del].cnt --, splay(del, 0);
    else {
        tr[suc].s[0] = 0;
        pushup(suc);
        splay(suc, 0);
    }
}

int get_rank(int v) {
    insert(v);
    int res = tr[tr[root].s[0]].sz;
    del(v);
    return res;
}

int get_val(int k) {
    int x = root;
    while(true) {
        int y = tr[x].s[0];
        if(tr[y].sz + tr[x].cnt < k) {
            k -= tr[y].sz + tr[x].cnt;
            x = tr[x].s[1];
        } else {
            if(tr[y].sz >= k) x = y;
            else break;
        }
    }
    splay(x, 0);
    return tr[x].v;
}

void solve() {
    insert(-inf); insert(inf);
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
        if(op==3) res ^= (last = get_rank(x));
        if(op==4) res ^= (last = get_val(x+1));
        if(op==5) res ^= (last = tr[get_pre(x)].v);
        if(op==6) res ^= (last = tr[get_suc(x)].v);
    }
    cout << res << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}