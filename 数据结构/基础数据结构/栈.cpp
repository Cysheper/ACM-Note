#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll

template<typename T>
struct Stack {
    vector<T> stk;

    void push(int x) {
        stk.push_back(x);
    }

    T top() {
        return stk.back();
    }

    void pop() {
        stk.pop_back();
    }

    int size() {
        return stk.size();
    }
};

void solve() {
    Stack<int> stk;
    for(int i = 0; i < 10; ++ i) {
        stk.push(i);
    }
    while(stk.size()) {
        cout << stk.top() << " ";
        stk.pop();
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