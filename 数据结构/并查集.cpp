/* author: Cysheper */ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
struct DSU {
    int n;
    vector<int> par;
    DSU(int n) {
        par.resize(n + 1);
        for(int i = 1; i <= n; ++ i) par[i] = i;
    }

    int find(int x) {
        return par[x] = par[x] == x ? x : find(par[x]);
    }

    void unite(int x, int y) {
        par[find(x)] = find(y);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

};

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    DSU dsu(n);
    if(n==1) dsu.unite(x, y);
    else if(dsu.same(x,y)) cout << "Y" << '\n';
    else cout << "N" << '\n';
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _; cin >> _;
    while(_--) solve();
    return 0;
}
