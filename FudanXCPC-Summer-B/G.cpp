#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define ll long long int
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define maxn 20020
#define maxm 200020
#define maxb 
#define maxs 
#define M  
using namespace std;

struct ele{
	int x, y, v;
	ele(int x, int y, int v) : x(x), y(y), v(v){}
	ele(){}
	bool operator < (const ele b) const{
		return v > b.v;
	}
} e[maxm];
int n, m;
int ufs[maxn], sizn[maxn], size[maxn], sizv[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y, int v, int& ans){
	x = find_root(x), y = find_root(y);
	if (x == y) {
		if (size[x] == sizn[x]) return;
		else {size[x]++, sizv[x] += v, ans += v; return;}
	}
	else {
		if (size[x] == sizn[x] && size[y] == sizn[y]) return;
		else {
			ufs[x] = y, sizn[y] += sizn[x], size[y] += size[x], sizv[y] += sizv[x];
			size[y]++, sizv[y] += v;
			ans += v;
			return;
		}
	}
	
}

int main(){
	int x, y, z;
	while (scanf("%d%d", &n, &m) == 2){
		if (!n && !m) break;
		rep(i, 1, n) ufs[i] = i, sizn[i] = 1, size[i] = 0, sizv[i] = 0;
		rep(i, 1, m) scanf("%d%d%d", &x, &y, &z), x++, y++, e[i] = ele(x, y, z);
		sort(e + 1, e + 1 + m);
		int ans = 0;
		rep(i, 1, m) merge(e[i].x, e[i].y, e[i].v, ans); 
		/*
		int mx = 0;
		rep(i, 1, n){
			if (ufs[i] == i){
				if (size[i] <= sizn[i]) mx = max(mx, sizv[i]);
			}
		}
		*/
		printf("%d\n", ans);
	} 
	return 0;
}
