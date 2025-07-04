#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
// 二分最好的板子
int tar = 10;
bool check(int x, vector<int> &v) {
    if(v[x] <= tar) return true; 
    return false;
}


void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    
    int l = 0, r = n;
    
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid, v)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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