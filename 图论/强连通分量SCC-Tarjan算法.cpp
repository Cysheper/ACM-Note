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
const int N = 1e5 + 5 ;
vector<int> e[N];
// 时间戳 dfn[x], 追溯值low[x] 
int dfn[N], low[N], tot; 
// 手写栈
int stk[N], instk[N], top;
// SCC数组, SCC大小
int scc[N], siz[N], cnt;
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for(int y : e[x]) {
        if(!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y]) 
            low[x] = min(low[x], dfn[y]);
    }
    if(dfn[x] == low[x]) {
        int y; ++cnt;
        do {
            y = stk[top--]; instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(y != x);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i=0;i<=m;++i) {
        cin >> a >> b;
        e[a].push_back(b);
    }
    for(int i=1;i<=n;++i) tarjan(i);
    int ans = 0;
    for(int i=1;i<=cnt;++i) 
        if(siz[i] > 1) ans++;
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}