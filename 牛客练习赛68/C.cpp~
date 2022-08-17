#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 600020
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
using namespace std;

unsigned int SA, SB, SC; int n, m, q, LIM;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

int u[maxn], v[maxn], w[maxn], L[maxn];
void gen(){
    scanf("%d%d%d%u%u%u%d", &n, &m, &q, &SA, &SB, &SC, &LIM);
    for(int i = 1; i <= m; i++){
        u[i] = rng61() % n + 1;
        v[i] = rng61() % n + 1;
        w[i] = rng61() % LIM;
    }
    for(int i = 1; i <= q; i++){
        L[i] = rng61() % LIM;
    }
}

int lis[maxn << 1], cs = 0;

struct edge{
	int x, y, w;
	edge(int x, int y, int w) : x(x), y(y), w(w){}
	edge(){}
	bool operator < (const edge& b) const{
		return w < b.w;
	}
}e[maxn];
pii qq[maxn];

ll res[maxn], ans = 0;
int ufs[maxn], s[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y){
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ans += 1ll * s[x] * s[y];
	s[x] += s[y];
	ufs[y] = x;
}

int main(){
	gen();
	rep(i, 1, m) lis[++cs] = w[i];
	rep(i, 1, q) lis[++cs] = L[i];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, m) e[i] = edge(u[i], v[i], lower_bound(lis + 1, lis + 1 + cs, w[i]) - lis);
	sort(e + 1, e + 1 + m);
	rep(i, 1, q) qq[i] = pii(lower_bound(lis + 1, lis + 1 + cs, L[i]) - lis, i);
	sort(qq + 1, qq + 1 + q);
	rep(i, 1, n) ufs[i] = i, s[i] = 1; 
	int ptr = 1; ll allans = 0;
	rep(i, 1, m){
		while (ptr <= q && qq[ptr].fi < e[i].w) {
			res[qq[ptr].se] = ans;
			ptr++;
		}
		int noww = e[i].w;
		while (i <= m && e[i].w == noww){
			merge(e[i].x, e[i].y);
			i++;
		}i--;
	}
	while (ptr <= q) {
		res[qq[ptr].se] = ans;
		ptr++;
	}
	rep(i, 1, q) allans ^= res[i]; printf("%lld\n", allans);
	//rep(i, 1, q) printf("%lld\n", res[i]);
	return 0;
}
