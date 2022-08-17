#include <bits/stdc++.h>
#define maxr 100000
#define maxn 3000019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
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
char ss[maxn];
priority_queue<int> s;
int ans = 0;
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("C.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%s", ss + 1);
		int n = strlen(ss + 1);
		while (!s.empty()) s.pop();
		int now = 1;
		rep(i, 1, n){
			bool f = 0;
			while (i <= n && ss[i] == '?') f = 1, now++, i++;
			s.push(now), now = 1;
		}
		if (ss[n] == '^') s.push(now);
		ans = 0;
		int x, _x, num;
		per(i, 21, 0){
			if (s.empty()) break;
			x = _x = s.top(); s.pop();
			if (x < (1 << i)) {
				s.push(x);
				continue;
			}
			x -= (1 << i);
			ans |= (1 << i);
			s.push(x);
		}
		int sum = 0;
		while (!s.empty()) sum += s.top(), s.pop(); 
		if (sum & 1) ans ^= 1;
		printf("%d\n", ans);
	}
	return 0;
}
