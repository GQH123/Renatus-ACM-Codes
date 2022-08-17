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
#define maxp 18
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define DEBUG
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

/*int dpc[maxp][2][10];
bool vis[maxp][2][10];
ll DP_count(int pos, bool op, int num){
	if (pos < 0) return 0;
	if (visc[pos][op][num]) return dpc[pos][op][num];
	visc[pos][op][num] = 1;
	ll& ans = dpc[pos][op][num];
	if (op){
		srep(i, 0, num[pos]) {
			ans = DP(pos - 1, 0, num) + ((i == num) ? ten[pos - 1] : 0);
		}
	}
	else {
	}
	return ans;
}*/
ll ten[maxp];
ll suf[maxp];
int dig[maxp];

ll dpc[maxp][10];
bool visc[maxp][10];
ll DP_count(int pos, int num){
	if (pos < 0) return 0;
	if (visc[pos][num]) return dpc[pos][num];
	visc[pos][num] = 1;
	ll& ans = dpc[pos][num];
	ans = 0;
	if (pos) ans += dig[pos] * pos * ten[pos - 1];
	if (num < dig[pos]) ans += ten[pos];
	if (num == dig[pos]) ans += ((pos) ? suf[pos - 1] : 0) + 1;
	ans += DP_count(pos - 1, num);
	return ans;
}

/*bool vis[maxp][2][2];
ll dp[maxp][2][2];
ll DP(int pos, bool op, bool op2){
	if (pos < 0) return 0;
	if (vis[pos][op][op2]) return dp[pos][op][op2];
	vis[pos][op][op2] = 1;
	ll& ans = dp[pos][op][op2];
	ans = 0;
	if (op){
		if (op2){
			
		}
		srep(i, 0, dig[pos]) ans += (9 - i) * ten[pos - 1]; //can be optimized...
		srep(
		rep(i, dig[pos] + 1, 9) ans += DP_count(pos - 1, i);
		ans += DP(pos - 1);
	}
	else {
		rep(i, 
	}
	
	return ans;
}*/


//ll cal(int len, int num){ //the num of <num> in 0~99999...9 (<len> of 9)
//	return ten[len - 1];
//}

int dep(ll x){
	int cp = 0;
	while (x){
		dig[cp++] = x % 10;
		x /= 10;
	}
	suf[0] = dig[0];
	srep(i, 1, cp) suf[i] = suf[i - 1] + ten[i] * dig[i]; 
	return cp;
}


ll play(ll x){
	if (x < 10) return 0;
	int s = dep(x);
	/*ll res = DP(s - 1);
	#ifdef DEBUG
		printf("%lld\n", res);
	#endif
	return res;*/
	ll res = 0;
	rep(num, 1, 9) {
		if (num > dig[s - 1]) break;
		if (num == dig[s - 1]) rep(j, num + 1, 9) res += DP_count(s - 2, j);
		else res += (9 - num) * (s - 1) * ten[s - 2];
	}
	ll pre = dig[s - 1];
	per(i, s - 2, 1){
		rep(num, 0, 9){
			if (num == 0) {
				if (num == dig[i]) {
					res += (pre - 1) * (9 - num) * i * ten[i - 1];
					rep(j, num + 1, 9) res += DP_count(i - 1, j);
				}
				else {
					res += pre * (9 - num) * i * ten[i - 1];
				}
			}
			else if (num < dig[i]) {
				res += (pre + 1) * (9 - num) * i * ten[i - 1];
			}
			else if (num == dig[i]){
				rep(j, num + 1, 9) res += DP_count(i - 1, j);
				res += pre * (9 - num) * i * ten[i - 1];
			}
			else {
				res += pre * (9 - num) * i * ten[i - 1];
			}
		}
		pre = pre * 10 + dig[i];
	}
	//printf("%lld = %lld\n", x, res);
	rep(i, 0, s + 1) suf[i] = dig[i] = 0;
	rep(i, 0, s + 1) rep(j, 0, 9) visc[i][j] = dpc[i][j] = 0;
	return res;
}

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("B.in", "r", stdin);
		#endif
		
	ten[0] = 1;
	srep(i, 1, maxp) ten[i] = ten[i - 1] * 10;
	
	int T; ll x, y;
	read(T);
	rep(TT, 1, T) {
		read(x), read(y);
		printf("Case %d: %lld\n", TT, play(y) - play(x - 1)); 
	}
	return 0;
}
