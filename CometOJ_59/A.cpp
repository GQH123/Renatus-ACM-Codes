#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define ll long long int 
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f)? x : -x;
}

ll powe(int x, int y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con;
		con = con * con;
		y >>= 1;
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	read(T);
	while (T--){
		ll k, n;
		read(k), read(n);
		if (n == 2) {printf("1\n"); continue;}
		if (k == 1) {printf("%lld\n", n - 1); continue;}
		ll now = 0, _now = 0;
		int m = 0;
		ll power = 1;
		while (n >= now){
			m++;
			_now = now;
			now += power;
			power *= k;
		}
		m--;
		n -= _now;
		if (m == 1){
			printf("2\n");
			continue;
		}
		else {
			if (!n) printf("%d\n", m + m - 2);
			else if (n <= powe(k, m - 1)) printf("%d\n", m + m - 1);
			else printf("%d\n", m + m);
		}
	}
	return 0;
}
