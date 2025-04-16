/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define inf 0x3f3f3f3f
#define eps 1e-19
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// 二分图判定-染色法
const int M = 1005, N = 1e5;
struct edge {
    int v, w, ne; // 终点,边权,下一条边
}e[M]; // 边集
int idx, h[N], color[N];
// 记得加 memset(h, -1, sizeof(h)); 
// 带权添加
void add(int a, int b, int w) {
    e[idx] = {b, w, h[a]};
    h[a] = idx++;
}
// 染色法二分图的判定
bool dfs(int u, int c) {
    color[u] = c;
    for(int i=h[u];i;i=e[i].ne) {
        int v = e[i].v;
        if(!color[v]) {
            if(dfs(v, 3-c)) return 1;
        }
        else if(color[v] == c) return 1;
    }
    return 0;
}
bool flag = 0;
bool check(int n) {
    for(int i=1;i<=n;++i) {
        if(!color[i]) {
            if(dfs(i,1)) {
                flag = 1;
                break;
            }
        }
    }
    if(flag) return 0;
    else return 1;
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}