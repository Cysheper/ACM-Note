#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
int phi(int n) {
    int res = n;
    for(int i = 2; i <= n / i; ++ i) {
        if(n % i == 0) {
            res = res / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res = res / n * (n - 1);
    return res;
}
vector<int> get_phi(int n) {
    vector<int> p, vis(n + 5);
    vector<int> phi(n + 5);
    phi[1] = 1;
    for(int i = 2; i <= n; ++ i) {
        if(!vis[i]) {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for(int j = 0; i * p[j] <= n; ++ j) {
            int m = i * p[j];
            vis[m] = 1;
            if(i % p[j] == 0) {
                phi[m] = p[j] * phi[i];
                break;
            } else phi[m] = (p[j] - 1) * phi[i];
        }
    }
    return phi; 
}

void solve() {
    vector<int> phi =  get_phi(700);
    cout << phi[700];
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