/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
vector<int> ne(1e6, 0);
// KMP (主串，模式串) 返回所有模式串在子串中出现的位置
void KMP(string S,string P){
    ll n = P.size(), m = S.size();
    for (int i = 1, j = 0; i < n; ++i) {
        while(j && P[i] != P[j])
            j = ne[j - 1];
        if (P[i] == P[j])
            j++;
        ne[i] = j;
    }
    for (int i = 0, j = 0; i < m; ++i) {
        while(j && S[i] != P[j])
            j = ne[j - 1];
        if (S[i] == P[j])
            j++;
        if(j == n){
            cout << i - n + 2 << '\n';
            j = ne[j - 1];
        }
    }
}
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    KMP(s1,s2);
    for(int i=0;i<s2.size();++i) cout << ne[i] << " ";
    return 0;
}