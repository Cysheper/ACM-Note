// Author: Cysheper
// CreatedTime: 2025-07-15 02:39:45
// MyBlog: https://cysheper.top
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
#define N 200005
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]

int n, m, a[N];
vector<int> v;

struct node {
    int ch[2];
    int s;
} tr[N * 22];
int root[N], idx;

void build(int &x, int l, int r) {
    x = ++idx;
    if(l == r) return;
    int mid = (l + r) >> 1; 
    build(lc(x), l, mid);
    build(rc(x), m + 1, r);
}

void insert(int x, int &y, int l, int r, int v) {
    y = ++idx; tr[y] = tr[x]; tr[y].s ++;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(v <= mid) insert(lc(x), lc(y), l, mid, v);
    else insert(rc(x), rc(y), mid + 1, r, v);
}

int query(int x, int y, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int s = tr[lc(y)].s - tr[lc(x)].s;
    if(k <= s) return query(lc(x), lc(y), l, mid, k);
    else return query(rc(x), rc(y), mid + 1, r, k - s);
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