#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
template<class T>
struct Queue {
    unique_ptr<T[]> arr;
    int front;
    int back;
    int sz = 10;

    Queue(): arr(new T[10]), front(0), back(0), sz(10) {}

    void expand() {
        sz *= 2;
        unique_ptr<T[]> temp(new T[sz]);
        for(int i = front; i <= back; ++ i) {
            
        }
    }   

};



void solve() {
    
    
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