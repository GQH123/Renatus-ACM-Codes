#include <bits/stdc++.h>
#define maxr 100000
#define maxn 1015
#define maxb
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
int n, k;
int v[maxn];
multiset<int> s;
multiset<int> :: iterator it;
bool judge(int ans){
	s.clear();
	rep(i, 1, n) s.insert(v[i]);
	int now = 1, rest = ans;
	while (now <= k && !s.empty()){
		it = s.upper_bound(rest);
		if (it == s.begin()) {
			now++, rest = ans;
			continue;
		}
		--it, rest -= *it;
		s.erase(it);
	}
	return now <= k;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	int T;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		int sum = 0;
		read(n), read(k);
		rep(i, 1, n) read(v[i]), sum += v[i];
		int ans = (sum - 1) / k + 1;
		while (1){
			if (judge(ans)){
				printf("%d\n", ans); 
				break;
			}
			ans++;
		}
	}
	return 0;
}
