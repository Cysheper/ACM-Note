/* author: Cysheper */ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 2e5 + 5;
int par[N], rk[N];
// 初始化n个元素
void init(int n) {
    for(int i = 1;i <= n;++i) par[i] = i;
}
// 查询树的根
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}
// 合并 :路径压缩
int unite(int x, int y) {
    x = find(x);y = find(y);
    return x == y ? 0 : par[x] = y;
}
// 合并 :按秩合并
void merge(int x, int y) {
    x = find(x);y = find(y);
    if(x == y) return;
    if(rk[x] > rk[y]) swap(x, y);
    par[x] = y;
    if(rk[x] == rk[y]) rk[y]++;
}
// 判断x和y是否联通
bool same(int x, int y) {
    return find(x) == find(y);
}

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    if(n==1) merge(x,y);
    else if(same(x,y)) cout << "Y" << '\n';
    else cout << "N" << '\n';
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _,__;cin >> _ >> __;
    init(_);
    while(__--) solve();
    return 0;
}
