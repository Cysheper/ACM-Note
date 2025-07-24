#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

void solve() {
    int n; cin >> n;
    vector<int> v1(n);;
    vector<int> v2(n);
    for(int &i: v1) cin >> i;
    for(int &i: v2) cin >> i;

    stack<int> stk;
    int idx = 0;

    for(int i = 0; i < n; ++ i) {
        stk.push(v1[i]);

        while(stk.top() == v2[idx]) {
            stk.pop(); idx ++;
            if(stk.empty()) break;
        }
    }
    if(stk.empty()) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1; 
    cin >> _;
    while(_ --) solve();
    return 0;
}