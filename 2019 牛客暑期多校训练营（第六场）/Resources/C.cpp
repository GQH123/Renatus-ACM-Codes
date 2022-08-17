#include <bits/stdc++.h>
#define maxr 100005
#define maxn 110105
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ms(a, b) memset(a, b, sizeof(a))
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
struct PT{
    int last, tot, d[maxn], go[maxn][26], fail[maxn], len[maxn];
    void init(){
        ms(go, 0), ms(fail, 0), ms(len, 0);
        last = 0;
        fail[0] = fail[1] = 1, len[tot = 1] = -1;
    }
    ll ans;
    set<int> sss;
    set<pii> ss;
    set<pii> :: iterator it;
    void dfs(int x, int d){
        sss.insert(x);
        if (fail[x] != 1 && fail[x] != 0 && !sss.count(fail[x])){
            it = ss.lower_bound(pii(fail[x], -1));
            if (it == ss.end() || (it -> fi) != fail[x]) ss.insert(pii(fail[x], x));
        }
        ans += d + ss.size();
        rep(i, 0, 25){
            if (!go[x][i]) continue;
            int k = go[x][i];
            dfs(k, d + 1);
        }
        if (fail[x] != 1 && fail[x] != 0 && !sss.count(fail[x])){
            it = ss.lower_bound(pii(fail[x], -1));
            if (it != ss.end() && (it -> fi) == fail[x] && (it -> se) == x) ss.erase(it);
        }
        sss.erase(x);
    }
    ll build(char* s){
        int n = strlen(s + 1), now, id;
        rep(i, 1, n){
            now = last, id = s[i] - 'a';
            while (s[i] != s[i - len[now] - 1]) now = fail[now];
            if (!go[now][id]){
                int _now = fail[now];
                while (s[i] != s[i - len[_now] - 1]) _now = fail[_now];
                fail[++tot] = go[_now][id], len[tot] = len[now] + 2, go[now][id] = tot, d[tot] = d[fail[tot]] + 1;
            }
            last = go[now][id];
        }
        ans = 0;
        rep(i, 0, 25) if (go[0][i]) dfs(go[0][i], 0);
        rep(i, 0, 25) if (go[1][i]) dfs(go[1][i], 0);
        return ans;
    }
}pt;
 
char s[maxn];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("C.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    rep(TT, 1, T){
        scanf("%s", s + 1);
        pt.init();
        printf("Case #%d: %lld\n", TT, pt.build(s));
    }
    return 0;
}
