/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll
const int N = 2e5 + 5;
class MS {
private:
    int b[N];
public:
    int ans = 0; // 求逆序对
    void msort(int l,int r, vector<int> &arr){
        if(l >= r) return;
        int mid = (l + r) >> 1;
        msort(l, mid, arr);
        msort(mid + 1,r,arr);
        int i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) b[k++] = arr[i++];
            else { b[k++] = arr[j++]; ans += mid - i + 1; }
        }
        while(i <= mid) b[k++] = arr[i++];
        while(j <= r) b[k++] = arr[j++];
        for(int i = l; i <= r; ++i) arr[i] = b[i];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    MS arr;
    arr.msort(0, n-1, v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n" << arr.ans;
}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}