#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 101005
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;
 
char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}
 
int n;
int num[maxn], pre[maxn];
char s[maxn];
map<int, int> sa;
int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    rep(i, 1, n) num[i] = s[i] - '0';
    rep(i, 1, n) pre[i] = pre[i - 1] + ((num[i]) ? 1 : -1);
    per(i, n, 1) sa[pre[i]] = i; sa[0] = 0;
    int ans1 = 0;
    rep(i, 1, n) ans1 = max(ans1, i - sa[pre[i]]);
     
    int num1 = 0, num0 = 0;
    rep(i, 1, n) {
        if (num[i]) num1++;
        else num0++;
    }
    printf("%d %d", ans1, 2 * min(num1, num0));
    return 0;
}
