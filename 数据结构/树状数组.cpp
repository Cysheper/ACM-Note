/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long uint;
typedef long double ld;
#define int ll
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi first
#define se second
#define bg begin
#define en end
#define gt greater
#define max_ max_element
#define min_ min_element
const int MAXN = 500010;
int n,m;
int a[MAXN],c[MAXN];
int lowbit(int x) {
    return x & (-x);
}
int sum(int x) {
    int res = 0;
    for(int i = x; i ; i -= lowbit(i)) res += c[i];
    return res;
}
void add(int x,int y) {
    for(int i = x; i <= n; i += lowbit(i)) c[i] += y;
}

void solve() {
    
}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while(_--) solve();
    return 0;
}