#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxn 100020 
#define maxb 240
#define ll long long int 
#define ld long double
#define pb push_back
#define pc putchar
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pdd pair<double, double>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

int num[10];
ll process(int x){
	rep(i, 0, 9) num[i] = 0;
	while (x){
		num[x % 10]++;
		x /= 10;
	}
	ll y = 0;
	rep(i, 1, 10){
		int _i = i % 10;
		rep(j, 1, num[_i]){
			y = y * 10 + _i;
		}
	}
	return y;
}
int n, m, ct = 0, a[maxn], b[maxn], l[maxn], r[maxn];

map<ll, int> id;
int que[2], hav[maxn], pos[maxn], top[maxn], bot[maxn];

pli operator + (pli a, pli b){
	return pli(a.fi + b.fi, a.se + b.se);
}
pli c[2][maxb][maxn];
void add(int ps, int x, pli v, int op){
	while (x <= n){
		c[op][ps][x] = c[op][ps][x] + v;
		x += lowbit(x);
	}
}
pli get(int ps, int x, int op){
	pli ans = pli(0, 0);
	while (x){
		ans = ans + c[op][ps][x];
		x -= lowbit(x);
	}
	return ans;
}

void init(){
	int siz = (int)sqrt(1.0 * n * log(n) / log(2));
	rep(i, 1, n) pos[i] = (i - 1) / siz + 1;
	for (register int i = 1; i <= n; i += siz){
		top[pos[i]] = i;
		bot[pos[i]] = min(i + siz - 1, n);
		rep(j, i, min(i + siz - 1, n)){
			add(pos[j], l[j], pli(l[j], 1), 0);
			add(pos[j], r[j] - 1, pli(r[j] - 1, 1), 1);
		}
	}
	//rep(i, 1, n) cerr << i << ':' << pos[i] << ' ' << top[pos[i]] << ' ' << bot[pos[i]] << endl;
}
ll play(ll x, ll y){
	//cerr << x << ' ' << y << endl;
	ll ans = 0;
	if (pos[x] == pos[y]) {
		rep(i, x, y){
			if (y < l[i]) continue;
			else if (y < r[i]) ans += y - l[i] + 1;
			else ans += r[i] - l[i]; 
		}
		return ans;
	}
	rep(i, pos[x] + 1, pos[y] - 1){
		pli pli0 = get(i, y, 0), pli1 = get(i, y, 1);
		ans -= pli0.fi + (bot[i] - top[i] + 1 - pli0.se) * y;
		ans += pli1.fi + (bot[i] - top[i] + 1 - pli1.se) * y;
		ans += bot[i] - top[i] + 1;
	}
	rep(i, x, bot[pos[x]]){
		if (y < l[i]) continue;
		else if (y < r[i]) ans += y - l[i] + 1;
		else ans += r[i] - l[i]; 
	}
	rep(i, top[pos[y]], y){
		if (y < l[i]) continue;
		else if (y < r[i]) ans += y - l[i] + 1;
		else ans += r[i] - l[i]; 
	}
	return ans;
}

void recover(){
	id.clear(); ct = 0;
	rep(i, 1, n) l[i] = r[i] = 0;
	int blo = pos[n];
	rep(i, 1, n) pos[i] = 0;
	rep(i, 1, blo) bot[i] = top[i] = 0;
	rep(i, 0, 1) rep(j, 1, blo) rep(k, 1, n) c[i][j][k] = pli(0, 0);
}
int main(){
	//cerr << sizeof(c) << endl;
	while (scanf("%d%d", &n, &m) == 2){
		rep(i, 1, n) scanf("%d", a + i); 
		rep(i, 1, n){
			ll y = process(a[i]);
			if (!id.count(y)) id[y] = ++ct;
			b[i] = id[y];
		}
		int lptr = 0, rptr = 0;
		rep(i, 1, n) hav[i] = 0; que[0] = que[1] = -1;
		rep(i, 1, n){
			while (lptr <= n && que[0] == -1) {
				++lptr, hav[b[lptr]]++;
				if (hav[b[lptr]] > 1) que[0] = b[lptr];
			}
			l[i] = lptr;
			hav[b[i]]--;
			if (b[i] == que[0]) que[0] = -1;
		}
		rep(i, 1, n) hav[i] = 0; que[0] = que[1] = -1;
		rep(i, 1, n){
			while (rptr <= n && (que[1] == -1 || que[0] == -1)) {
				++rptr, hav[b[rptr]]++;
				if (hav[b[rptr]] > 1) {
					if (que[0] == -1) que[0] = b[rptr];
					else que[1] = b[rptr];
				}
			}
			r[i] = rptr;
			hav[b[i]]--;
			if (b[i] == que[1]) que[1] = -1;
			else if (b[i] == que[0]) que[0] = -1;
		}
		//rep(i, 1, n) cerr << l[i] << ' ' << r[i] << endl;
		init();
		ll lastans = 0, x, y;
		rep(i, 1, m){
			scanf("%lld%lld", &x, &y);
			x += lastans, y -= lastans;
			lastans = play(x, y);
			printf("%lld\n", lastans);
		}
		recover();
	} 
	return 0;
}
