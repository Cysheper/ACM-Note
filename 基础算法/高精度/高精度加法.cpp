#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size() < b.size()) swap(a, b);
    string ans = "";
    int sz = max(a.size(), b.size());
    int sz1 = min(a.size(), b.size());
    int idx = 0;
    for(int i = 0; i < sz; ++ i) {
        if(i >= sz1) {
            ans += a[i] + idx;
            idx = 0;
        }
        else {
            int n1 = a[i] - '0';
            int n2 = b[i] - '0';
            int c = (n1 + n2 + idx) % 10;
            ans += c + '0';
            if((n1 + n2 + idx) >= 10) {
                idx = 1;
            } 
            else idx = 0;
        }
    }
    if(idx) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
    
}




void solve() {
    string s, b;
    cin >> s >> b;
    cout << add(s, b) << "\n";

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