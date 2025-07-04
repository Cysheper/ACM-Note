#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll



void solve() {
    string s; cin >> s;
    stack<int> stk;
    string ss;
    for(int i = 0; i < s.size() - 1; ++ i) {
        if(s[i] == '-') {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b - a);
        }
        else if(s[i] == '+') {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b + a);
        }
        else if(s[i] == '*') {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b * a);
        } 
        else if(s[i] == '/') {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            stk.push(b / a);
        }
        else if(s[i] != '.') {
            ss += s[i];
        } else {
            stk.push(stoi(ss));
            ss = "";
        }
    }
    cout << stk.top() << "\n";
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