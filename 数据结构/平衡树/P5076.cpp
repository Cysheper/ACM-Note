// 支持排名的集合
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ordered_set<int> s;
    int n; cin >> n;
    int op, x;
    while (n --) {
        cin >> op >> x;
        if (op == 5) {
            // 插入 x
            s.insert(x);
        } else if (op == 1) {
            // 查询 x 的排名（小于 x 的数量 + 1）
            cout << s.order_of_key(x) + 1 << '\n';
        } else if (op == 2) {
            // 查询排名为 x 的数（排名从 1 开始）
            cout << *s.find_by_order(x - 1) << '\n';
        } else if (op == 3) {
            // 查询 x 的前驱
            auto it = s.lower_bound(x);
            if (it == s.begin()) cout << -2147483647 << '\n';
            else cout << *prev(it) << '\n';
        } else if (op == 4) {
            // 查询 x 的后继
            auto it = s.upper_bound(x);
            if (it == s.end()) cout << 2147483647 << '\n';
            else cout << *it << '\n';
        }
    }

    return 0;
}
