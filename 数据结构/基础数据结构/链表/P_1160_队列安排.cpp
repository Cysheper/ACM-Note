#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
struct node {
    int l, r;

    node() {
        l = 0;
        r = 0;
    }
}lst[100005];

void solve() {
    int n; cin >> n;

    int head = 1;

    for(int i = 2; i <= n; ++ i) {
        int x, op; cin >> x >> op;
        if(x == head && op == 0) {
            head = i;
        }
        if(op == 1) {
            lst[lst[x].r].l = i;
            lst[i].r = lst[x].r;
            lst[x].r = i;
            lst[i].l = x;
        } else {
            lst[lst[x].l].r = i;
            lst[i].l = lst[x].l;
            lst[x].l = i;
            lst[i].r = x;
        }
    }

    int m; cin >> m;

    for(int i = 1; i <= m; ++ i) {
        int x; cin >> x;
        if(x == head) {
            head = lst[head].r;
            continue;
        }
        lst[lst[x].l].r = lst[x].r;
        lst[lst[x].r].l = lst[x].l;
        lst[x].l = 0;
        lst[x].r = 0;
    }

    while(head) {
        cout << head << " ";
        head = lst[head].r;
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