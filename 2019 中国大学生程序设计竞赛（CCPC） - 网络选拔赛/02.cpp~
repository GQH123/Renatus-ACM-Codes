#include <bits/stdc++.h>
#define maxr 100000
#define maxn 150019
#define maxnode 2000000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define lowbit(x) (x & -x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int num[20];
void out(int x){
	int d = 0;
	while (x){
		num[++d] = x % 10;
		x /= 10;
	}
	per(i, d, 1) printf("%d", num[i]);
	printf("\n");
}

int n, m;
int a[maxn];
int h[maxn];
int ct = 0;
int ch[maxnode][2];
set<int> s;
set<int> :: iterator it;
void insert(int x, int i){
	h[i] = ++ct;
	int now = h[i], pre = h[i + 1], l = 1, r = n;
	while (l != r){
		int mid = ((r - l) >> 1) + l;
		if (x <= mid) {
			ch[now][1] = ch[pre][1];
			ch[now][0] = ++ct, now = ch[now][0];
			pre = ch[pre][0];
			r = mid;
		}
		else {
			ch[now][0] = ch[pre][0];
			ch[now][1] = ++ct, now = ch[now][1];
			pre = ch[pre][1];
			l = mid + 1;
		}
	}
}
int qd;
int get(int l, int r, int o){
	if (!o) return n + 1;
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l, ans = n + 1;
	if (qd <= mid && ch[o][0]){
		ans = get(l, mid, ch[o][0]);
		if (ans < qd) ans = n + 1;
	}
	if (ans == n + 1) return get(mid + 1, r, ch[o][1]);
	else return ans;
}
int get(int x, int d){
	qd = d;
	int ans = get(1, n, h[x + 1]);
	it = s.lower_bound(d);
	if (it != s.end()) ans = min(ans, *it);
	return ans;
}

int lastans = 0;
void recover(){
	rep(i, 1, ct) ch[i][0] = ch[i][1] = 0;
	s.clear(); lastans = ct = 0;
	rep(i, 1, n + 1) h[i] = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("02.in", "r", stdin);
	#endif
	int T, x, y;
	read(T);
	while (T--){
		read(n), read(m);
		rep(i, 1, n) read(a[i]); 
		per(i, n, 1) insert(a[i], i); 
		rep(i, 1, m){
			read(x);
			if (x == 1){
				read(x);
				x ^= lastans;
				s.insert(a[x]);
			}
			else if (x == 2){
				read(x), read(y);
				x ^= lastans, y ^= lastans;
				lastans = get(x, y);
				out(lastans);
			}
		}
		recover();
	}
	return 0;
}
