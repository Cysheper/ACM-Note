/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi first
#define se second
#define gt greater
#define max_ max_element
#define min_ min_element
const int mod = 1e9 + 7;
inline int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a % b);
}
inline int lcm(int a,int b) {
    return (a / gcd(a, b)) * b % mod;
}
const int MAXN = 2e5 + 5;  // 假设数组的最大长度
const int LOG = 18;    // 对应 log2(MAXN) + 1
//int min_arr[MAXN][LOG];      // 最小值
//int max_arr[MAXN][LOG];      // 最大值
//int gcd_arr[MAXN][LOG];      // GCD
int lcm_arr[MAXN][LOG];      // LCM
int log_2[MAXN + 1]; // 预计算 log2

// 预处理：构建 ST 表
void buildST(vector<int>& arr) {
    int n = arr.size();
    // 初始化 log2Table
    log_2[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log_2[i] = log_2[i / 2] + 1;
    }
    // 初始化 ST 表的第一列
    for (int i = 1; i <= n; ++i) {
        //max_arr[i][0] = arr[i];
        //min_arr[i][0] = arr[i];
        //gcd_arr[i][0] = arr[i];
        lcm_arr[i][0] = arr[i];
    }
    // 填充 ST 表
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            //max_arr[i][j] = max(max_arr[i][j - 1], max_arr[i + (1 << (j - 1))][j - 1]);
            //min_arr[i][j] = min(min_arr[i][j - 1], min_arr[i + (1 << (j - 1))][j - 1]);
            //gcd_arr[i][j] = gcd(gcd_arr[i][j - 1], gcd_arr[i + (1 << (j - 1))][j - 1]);
            lcm_arr[i][j] = lcm(lcm_arr[i][j - 1], lcm_arr[i + (1 << (j - 1))][j - 1]) % mod;
        }
    }
}

// 查询区间 [L, R] 的最大值
// int query_max(int L, int R) {
//     int len = R - L + 1;
//     int j = log_2[len];
//     return max(max_arr[L][j], max_arr[R - (1 << j) + 1][j]);
// }
// // 查询区间 [L, R] 的最小值
// int query_min(int L, int R) {
//     int len = R - L + 1;
//     int j = log_2[len];
//     return min(min_arr[L][j], min_arr[R - (1 << j) + 1][j]);
// }
// // 查询区间 [L, R] 的gcd
// int query_gcd(int L, int R) {
//     int len = R - L + 1;
//     int j = log_2[len];
//     return gcd(gcd_arr[L][j], gcd_arr[R - (1 << j) + 1][j]);
// }
// 查询区间 [L, R] 的lcm
int query_lcm(int L, int R) {
    int len = R - L + 1;
    int j = log_2[len]; 
    return lcm(lcm_arr[L][j], lcm_arr[R - (1 << j) + 1][j]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> h(m + 1);
    for (int i = n; i <= m;++i) h[i] = i;
    buildST(h);
    cout << query_lcm(n, m) << '\n';
    
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}