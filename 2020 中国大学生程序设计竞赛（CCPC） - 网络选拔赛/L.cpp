#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb 40
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int A, B, K, W;
int numa[maxb], numb[maxb], numk[maxb], numw[maxb];
int dep(int x, int* num) {
	srep(i, 0, maxb) num[i] = 0;
	int s = 0;
	if (!x) {	
		num[s++] = 0;
		return s - 1;
	}
	while (x){ 
		num[s++] = x & 1;
		x >>= 1;
	}
	return s - 1;
}

/*
int vis[maxb][4][2][2][2];
ll dp[maxb][4][2][2][2];
int idx = 0;
ll DP(int pos, int opa, int opb, int opk, int opw) {
	if (pos == -1) return opa <= 1;
	if (vis[pos][opa][opb][opk][opw] == idx) return dp[pos][opa][opb][opk][opw];
	vis[pos][opa][opb][opk][opw] = idx;
	ll& ans = dp[pos][opa][opb][opk][opw]; ans = 0;
	if (opa > 1) {
		int limb = (opb) ? numb[pos] : 1;
		int limk = (opk) ? numk[pos] : 1;
		int limw = (opw) ? numw[pos] : 1;
		int lima = (opa) ? numa[pos] : 1;
		rep(b, 0, limb){
			rep(k, 0, limk) { 
				if (!b && !k) continue;
				int _opa = (opa == 2) ? ((lima) ? 3 : 2) : 3;
				//int _opa = (opa) ? ((0 < lima) ? 0 : 1) : 0;
				int _opb = (opb) ? ((b < limb) ? 0 : 1) : 0;
				int _opk = (opk) ? ((k < limk) ? 0 : 1) : 0;
				int _opw = (opw) ? ((b < limw) ? 0 : 1) : 0;
				
				if (b && k) {
					_opa = (_opa == 2) ? 1 : 0;
					ans += DP(pos - 1, _opa, _opb, _opk, _opw);
				}
				else {
					ans += DP(pos - 1, _opa, _opb, _opk, _opw);
				}
			}
		}
	}
	else {
		int limb = (opb) ? numb[pos] : 1;
		int limk = (opk) ? numk[pos] : 1;
		int limw = (opw) ? numw[pos] : 1;
		int lima = (opa) ? numa[pos] : 1;
		rep(b, 0, limb){
			rep(k, 0, limk) {
			
				if (b && k) {
					if (opa || opw) continue; 
				}
				if ((b ^ ((b + k) & 1)) > limw) continue;
				
				int _opa = (opa) ? ((b + k < lima) ? 0 : 1) : 0;
				int _opb = (opb) ? ((b < limb) ? 0 : 1) : 0;
				int _opk = (opk) ? ((k < limk) ? 0 : 1) : 0;
				int _opw = (opw) ? (((b ^ ((b + k) & 1)) < limw) ? 0 : 1) : 0;
				ans += DP(pos - 1, _opa, _opb, _opk, _opw);
				
				if (!b && !k && opa) {
					if (lima && limw) {
						_opw = (opw) ? ((1 < limw) ? 0 : 1) : 0;
						ans += DP(pos - 1, 2, _opb, _opk, _opw);
					}
				}
			}
		}
	}
	return ans;
}
*/

int vis[maxb][2][2][2][2][2];
ll dp[maxb][2][2][2][2][2];
int idx = 0;
ll DP(int pos, int opa, int opb, int opk, int opw, int up) {
	if (pos == -1) return !up;
	if (vis[pos][opa][opb][opk][opw][up] == idx) return dp[pos][opa][opb][opk][opw][up];
	vis[pos][opa][opb][opk][opw][up] = idx;
	ll& ans = dp[pos][opa][opb][opk][opw][up]; ans = 0;
	if (up) {
		int limb = (opb) ? numb[pos] : 1;
		int limk = (opk) ? numk[pos] : 1;
		int limw = (opw) ? numw[pos] : 1;
		int lima = (opa) ? numa[pos] : 1;
		rep(b, 0, limb){
			rep(k, 0, limk) { 
				rep(_up, 0, 1){
					if (b + k + _up <= 1) continue;
					int a = b + k + _up - 2;
					if (a > lima) continue; 
					if ((b ^ (a & 1)) > limw) continue;
					int _opa = (opa) ? ((a < lima) ? 0 : 1) : 0;
					int _opb = (opb) ? ((b < limb) ? 0 : 1) : 0;
					int _opk = (opk) ? ((k < limk) ? 0 : 1) : 0;
					int _opw = (opw) ? (((b ^ (a & 1)) < limw) ? 0 : 1) : 0;
					ans += DP(pos - 1, _opa, _opb, _opk, _opw, _up);
				} 
			}
		}
	}
	else {
		int limb = (opb) ? numb[pos] : 1;
		int limk = (opk) ? numk[pos] : 1;
		int limw = (opw) ? numw[pos] : 1;
		int lima = (opa) ? numa[pos] : 1;
		rep(b, 0, limb){
			rep(k, 0, limk) {
				if (b && k) continue;
				rep(_up, 0, 1) {
					if (b + k + _up > lima) continue; 
					int a = b + k + _up;
					if ((b ^ (a & 1)) > limw) continue;
					int _opa = (opa) ? ((a < lima) ? 0 : 1) : 0;
					int _opb = (opb) ? ((b < limb) ? 0 : 1) : 0;
					int _opk = (opk) ? ((k < limk) ? 0 : 1) : 0;
					int _opw = (opw) ? (((b ^ (a & 1)) < limw) ? 0 : 1) : 0;
					ans += DP(pos - 1, _opa, _opb, _opk, _opw, _up);
				}
			}
		}
	}
	return ans;
}

int main(){
	int T; read(T);
	while (T--){ 
		read(A), read(B), read(K), read(W);
		int mx = 0; 
		mx = max(mx, dep(A, numa));
		mx = max(mx, dep(B, numb));
		mx = max(mx, dep(K, numk));
		mx = max(mx, dep(W, numw)); 
		ll ans = 0;
		idx++, ans += DP(mx, 1, 1, 1, 1, 0);
		idx++, dep(A, numb), dep(B, numa), ans += DP(mx, 1, 1, 1, 1, 0); 
		ans -= (min(A, B) + 1);
		printf("%lld\n", ans);
	}
	return 0;
}

