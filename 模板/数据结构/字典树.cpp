/* author: Cysheper */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define MAXN 2000 * 75 + 5
int trie[MAXN][26]; //每个结点都有可能有26个子结点
int word[MAXN]; //用于记录以这个结点为单词末尾单词个数
char str[80];
// n个字符串,最长链长为ans
int n, tot = 0,ans = 0;
// 字典树,插入字符串,最长链长为ans
void insert (char *str) {
    int u = 0; //根结点
    int len = strlen(str);
    int res = 0; //表示字典树路径上存有几个别的单词
    for (int i = 0; i < len;++i) {
        int a = str[i] - 'a'; //映射小写字母
        if (trie[u][a] == 0) //如果没有这个结点
            trie[u][a] = ++tot;
        u = trie[u][a]; //跳转到该结点
        res += word[u]; //如果这个结点存有单词则增加
    }
    word[u]++; //以该结点结尾的单词的个数加一
    if (res + 1 > ans) //比较链长最大值
        ans = res + 1;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        insert(str);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}