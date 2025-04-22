/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll

void qsort(int l, int r, vector<int> &arr) {
    if(l == r) return;
    int i = l - 1, j = r + 1, x = arr[(l+r)>>1];
    while(i < j) {
        i++;j--;
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    qsort(l, j, arr);
    qsort(j + 1, r , arr);
}


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    qsort(0, n-1, v);
    for (int i : v) {
        cout << i << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}