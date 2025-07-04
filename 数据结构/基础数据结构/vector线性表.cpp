#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
template<class T>
struct Vector {
    unique_ptr<T[]> arr;
    int pos;
    int sz;

    Vector() : arr(new T[10]), pos(0), sz(10) {}

    Vector(int n) : arr(new T[n]), pos(0), sz(n) {}

    Vector(int n, T obj) : arr(new T[n]), pos(0), sz(n) {
        for(int i = 0; i < n; ++ i) arr[i] = obj;
        pos = n;
    }

    void expand() {
        sz *= 2;
        unique_ptr<T[]> temp(new T[sz]);

        for(int i = 0; i < pos; ++ i) 
            temp[i] = arr[i];
        
        arr = move(temp);
    }

    void push_back(const T &v) {
        if(pos >= sz - 2) {
            expand();
        } 
        arr[pos++] = v;
    }

    void pop_back() {
        if(pos > 0) pos --;
    }

    T back() {
        return arr[pos-1];
    }

    

    T& operator[](int index) {
        return arr[index];
    }

    int size() const {
        return pos;
    }
};

void solve() {
    Vector<int> v(10, 50);
    v[5] = 100;
    for(int i = 0; i < 10; ++ i) {
        cout << v[i] << " ";
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