#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define maxn 2020
#define maxm
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int n; char g[maxn][maxn];

inline int id(char ch){
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    else return ch - 'A' + 26;
}
bool judge(int x){
    rep(i, 1, n - x + 1){
        rep(j, 1, n - x + 1){
            rep(s, 1, x) rep(t, 1, x) {
                if (g[s + i - 1][t + j - 1] != g[x - t + i][x - s + j]) goto skip;
            }
            return true;
            skip:;
        }
    }
    return false;
}
int lower_bound(int l, int r){
    while (l != r){
        int mid = ((r - l + 1) >> 1) + l;
        if (judge(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
    while (scanf("%d", &n) == 1 && n){
        rep(i, 1, n) scanf("%s", g[i] + 1);
        printf("%d\n", lower_bound(1, n));
    }
	return 0;
}
