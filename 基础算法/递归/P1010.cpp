#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

void dfs(int x) {
    while(x != 0) {
        int num = 0;
        while(pow(2, num) <= x) num ++;
        num --;
        cout << 2;
        if(num == 0 || num == 2) {
            cout << "(" << num << ")";
            x -= pow(2, num);
            if(x != 0) cout << "+";
            continue;
        }
        if(num == 1) {
            x -= 2;
            if(x != 0) cout << "+";
            continue;
        }
        else cout << "(";
        dfs(num);
        cout << ")";
        x -= pow(2, num);
        if(x != 0) cout << "+";
    }
}



void solve() {
    int n; cin >> n;
    dfs(n);
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