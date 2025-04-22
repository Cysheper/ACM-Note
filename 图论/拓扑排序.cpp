/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 105;
// G[] 存图, tp[] 拓扑排序的结果
vector<int> G[N], tp; 
int din[N]; // 入度 (存图时记得计算入度)
int n; // 点数
bool toposort() {
    queue<int> q;
    for(int i=1;i<=n;++i) {
        if(din[i]==0) q.push(i);
    } 
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        tp.push_back(x);
        for(auto c : G[x]) {
            if(--din[c] == 0) q.push(c);
        }
    }
    return tp.size() == n;
}   
void solve(){
    cin >> n;
    for(int i=1;i<=n;++i) {
        int a;cin >> a;
        while(a != 0) {
            G[i].push_back(a);
            din[a]++;
            cin >> a;
        }
    }
    toposort();
    for(auto c : tp) cout << c << " ";
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}