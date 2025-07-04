#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

template<typename T>
struct treap {
    vector<T> arr = { 0 };
    int cnt = 0;

    void up(int u) {
        int v = (u >> 1);
        if(v && arr[v] > arr[u]) {
            swap(arr[u], arr[v]);
            up(v);
        }
    }

    void push(T x) {
        arr.push_back(x);
        cnt ++;
        up(cnt);
    }

    void down(int u) {
        int v = u;
        int uu = u * 2;
        if(uu <= cnt && arr[uu] < arr[v]) v = uu;
        if(uu + 1 <= cnt && arr[uu + 1] < arr[v]) v = uu + 1;
        if(u != v) {
            swap(arr[u], arr[v]);
            down(v);
        }
    }

    void pop() {
        arr[1] = arr[cnt--];
        arr.pop_back();
        down(1);
    }
    
    T top() {
        return arr[1];
    }

    int size() {
        return cnt;
    }
};

void solve() {
    int n; cin >> n;
    treap<int> arr;
    for(int i = 0; i < n; ++ i) {
        int a; cin >> a;
        arr.push(a);
    }
    for(int i = 0; i < n; ++ i) {
        cout << arr.top() << " ";
        arr.pop();
    }
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