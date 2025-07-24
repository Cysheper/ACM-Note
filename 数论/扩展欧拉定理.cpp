// Author: Cysheper
// CreatedTime: 2025-07-21 13:58:58
// MyBlog: https://cysheper.top
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

// 欧拉函数
int get_phi(int m) {
    int res = m;
    for(int i = 2; i * i <= m; ++ i) {
        if(m % i == 0) {
            res = res / i * (i - 1);
            while(m % i == 0) m /= i;
        }
    }
    if(m > 1) res = res / m * (m - 1);
    return res;
}

// 降幂
int depow(int phi, string s) {
    int b = 0, flag = 0;
    for(auto i: s) {
        b = b * 10 + (i - '0');
        if(b >= phi) {
            flag = 1;
            b %= phi;
        }
    }
    if(flag) b += phi;
    return b;
}

// 快速幂
int quick_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, mod;
    string b;
    cin >> a >> mod >> b;
    ll phi = get_phi(mod);
    ll p = depow(phi, b);
    cout << quick_pow(a, p, mod);
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