#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 600020
#define ll long long int 
using namespace std;

int n, p[maxn], d[maxn], s[maxn];
ll sums[maxn], pres[maxn];
bool leaf[maxn];

/*
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
}
*/

int main(){
    int T; scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        rep(i, 1, n) leaf[i] = 1, s[i] = 0;
        rep(i, 2, n) scanf("%d", &p[i]), leaf[p[i]] = 0;
        ll ans = 0;
        d[1] = 0, ans++; rep(i, 2, n) d[i] = d[p[i]] + 1, ans += d[i] + 1;
        /*
        sub[1] = 0; rep(i, 2, n) {
        	if (p[i] == 1) sub[i] = i;
        	else sub[i] = sub[p[i]];
        }
        */
        per(i, n, 2) s[i]++, s[p[i]] += s[i]; 
        s[1]++;
    	/*
        per(i, n, 2){	
        	sums[i] += s[i];
        	sums[p[i]] += sums[i];
        }
        rep(i, 2, n) {	
        	pres[i] = sums[i];
        	pres[i] += pres[p[i]];
        }
        */
        rep(i, 1, n) {	
        	pres[i] = s[i];
        	pres[i] += pres[p[i]];
        }
        ll res = 0;
        rep(i, 1, n) {
            if (!leaf[i]) continue;
            //res = max(res, 1ll * d[i] * (n - 1 - s[sub[i]]) + 
            int len = d[i] + 1;
            res = max(res, 1ll * len * n - pres[i]);
        }
        printf("%lld\n", ans + res);
    }
	return 0;
}
