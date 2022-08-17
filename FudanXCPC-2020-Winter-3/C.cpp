#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 1200020
using namespace std;

const int M1 = 941;
const int M2 = 10627;

int p[maxn];
bool vis[maxn];
int son[maxn];
int cnt = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cnt] = i, son[i] = cnt;
		rep(j, 1, cnt){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
}

int lis[maxn];
ll ans1[maxn];
ll ans2[maxn];
ll ans[maxn];

ll power(ll x, ll y, ll M){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll get_inv(ll x, ll M){
	return power(x, M - 2, M);
}
/*inline ll cal(int k, ll M, int d){
	ll inv2 = (d == 1) ? 471 : 5314;
	return ((ll)k + 1) * ((ll)k + 2) % M * inv2 % M;
}*/
const int M = 10000007;
const int inv2 = 5000004;
inline ll cal(int k){
	return ((ll)k + 1) * ((ll)k + 2) % M * inv2 % M;
}



struct ele{
	int id, x;
	ele(int id, int x) : id(id), x(x){}
	ele(){}
	bool operator < (const ele b) const{
		return x < b.x;
	}
}a[maxn];

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("C.in", "r", stdin);
		#endif
	
	init();
	/*ans1[1] = ans2[1] = ans[1] = 1;
	srep(i, 2, maxn) {
		int x = i;
		ans1[i] = ans1[i - 1];
		ans2[i] = ans2[i - 1];
		while (x > 1) {
			int nex = son[x], s = 0;
			while (x > 1 && son[x] == nex) {
				s++;
				x /= p[nex];
			}
			ans1[i] = ans1[i] * get_inv(cal(lis[nex], M1, 1), M1) % M1;
			ans2[i] = ans2[i] * get_inv(cal(lis[nex], M2, 2), M2) % M2;
			lis[nex] += s;
			ans1[i] = ans1[i] * cal(lis[nex], M1, 1) % M1;
			ans2[i] = ans2[i] * cal(lis[nex], M2, 2) % M2;
			
			if (ans1[i] == 0) {
				printf("%d\n", i);
				rep(j, 1, cnt) printf("%d\n", lis[j]);
				return 0;
			}
		}
	}
	
	srep(i, 2, maxn) {
		ans[i] = (ans1[i] * get_inv(M2, M1) % M * M2 % M + ans2[i] * get_inv(M1, M2) % M * M1 % M) % M;
		//printf("%lld\n", ans1[i]);
	}
	int x;
	while (1){
		scanf("%d", &x);
		if (!x) return 0;
		printf("%lld\n", ans[x]);
	}*/
	
	int n = 0, x;
	while (1){
		scanf("%d", &x);
		if (!x) break;
		++n;
		a[n].x = x;
		a[n].id = n;
		//printf("%lld\n", ans[x]);
	}
	sort(a + 1, a + 1 + n);
	int ptr = 1;
	srep(i, 1, maxn) {
		if (ptr == n + 1) break;
		int x = i;
		while (x > 1) {
			int nex = son[x], s = 0;
			while (x > 1 && son[x] == nex) {
				s++;
				x /= p[nex];
			}
			lis[nex] += s;
		}
		if (a[ptr].x == i){
			ll nans = 1;
			rep(j, 1, cnt){
				if (p[j] > i) break;
				nans = nans * cal(lis[j]) % M;
			}
			while (ptr <= n && a[ptr].x == i) {
				ans[a[ptr].id] = nans;
				ptr++;
			}
		}
	}
	rep(i, 1, n) printf("%lld\n", ans[i]);
	return 0;
}
