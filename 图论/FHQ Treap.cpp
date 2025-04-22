/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define inf 0x3f3f3f3f
#define eps 1e-19
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 1e5 + 5;
struct node {
    int l, r;
    int val;
    int key;
    int sz;
}tree[N];
int n, root, idx;
int newnode(int v) {
    tree[++idx].val = v;
    tree[idx].key = rand();
    tree[idx].sz = 1;
    return idx;
}
void pushup(int p) {
    tree[p].sz = tree[tree[p].l].sz
        + tree[tree[p].r].sz + 1;
}
void split(int p, int v, int &x, int &y) {
    if(!p) {
        x = y = 0;
        return;
    }
    if(tree[p].val <= v) {
        x = p;
        split(tree[x].r, v, tree[x].r, y);
    } else {
        y = p;
        split(tree[y].l, v, x, tree[y].l);
    }
    pushup(p);
}
int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(tree[x].key < tree[y].key) {
        tree[x].r = merge(tree[x].r, y);
        pushup(x);
        return x;
    } else {
        tree[y].l = merge(x, tree[y].l);
        pushup(y);
        return y;
    }
}
void insert(int v) {
    int x, y, z;
    split(root, v, x, y);
    z = newnode(v);
    root = merge(merge(x, z), y);
}
void del(int v) {
    int x, y, z;
    split(root, v, x, z);
    split(x, v-1, x, y);
    y = merge(tree[y].l, tree[y].r);
    root = merge(merge(x, y), z);
}
int get_k(int p, int k) {
    if(k <= tree[tree[p].l].sz) 
        return get_k(tree[p].l, k);
    if(k == tree[tree[p].l].sz + 1) 
        return p;
    return get_k(tree[p].r, k-tree[tree[p].l].sz-1);
}
void solve() {
    
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}