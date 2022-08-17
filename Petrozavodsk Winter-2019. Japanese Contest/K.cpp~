#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 5019
#define maxr 100000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (ch != '-' && !('0' <= ch && ch <= '9')) ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int n, _n;
int a[maxn], _a[maxn], b[maxn], _b[maxn];
int v[maxn];
int ans1[maxn], ans2[maxn];
int l[maxn];
multiset<int> s;
multiset<int> :: iterator it;
pii lis[maxn];

void WAY_1(){
	n = _n, s.clear();
	rep(i, 1, n) l[i] = 0, a[i] = _a[i], lis[i] = pii(a[i], i);
	rep(i, 1, n) b[i] = _b[i], s.insert(b[i]);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n){
		pii op = lis[i];
		it = s.upper_bound(op.fi);
		if (it == s.end()) l[op.se] = 1;
		else s.erase(it);
	}
	sort(b + 1, b + 1 + n);
	rep(i, 1, n){
		if (!l[i]){
			l[i] = upper_bound(b + 1, b + 1 + n, a[i]) - b;
			if (l[i] == n + 1) l[i] = 1;
		}
	}
	rep(i, 1, n) v[i] = n - i + 1;
	rep(i, 1, n) per(j, l[i], 1) v[j]--; 
	rep(i, 1, n){
		bool f = 1;
		rep(j, l[i] + 1, n){
			if (!v[j]){
				f = 0, ans1[i] = b[j - 1];
				per(k, j - 1, l[i] + 1) v[k]--;
				break;
			}
		}
		if (f) {
			ans1[i] = b[n]; 
			per(k, n, l[i] + 1) v[k]--;
		}
	}
}
void WAY_2(){
	n = _n, s.clear();
	rep(i, 1, n) l[i] = 0, a[i] = _a[i];
	rep(i, 1, n) b[i] = _b[i], s.insert(b[i]);
	sort(b + 1, b + 1 + n);
	rep(i, 1, n){
		it = s.upper_bound(a[i]);
		if (it == s.end()) l[i] = 1;
		else s.erase(it);
	}
	rep(i, 1, n){
		if (!l[i]){
			l[i] = upper_bound(b + 1, b + 1 + n, a[i]) - b;
			if (l[i] == n + 1) l[i] = 1;
		}
	}
	rep(i, 1, n) v[i] = n - i + 1;
	rep(i, 1, n) per(j, l[i], 1) v[j]--; 
	rep(i, 1, n){
		bool f = 1;
		rep(j, l[i] + 1, n){
			if (!v[j]){
				f = 0, ans2[i] = b[j - 1];
				per(k, j - 1, l[i] + 1) v[k]--;
				break;
			}
		}
		if (f) {
			ans2[i] = b[n]; 
			per(k, n, l[i] + 1) v[k]--;
		}
	}
}
int main(){
	read(_n);
	rep(i, 1, _n) read(_a[i]);
	rep(i, 1, _n) read(_b[i]);
	WAY_2();
	WAY_1();
	int d = -1;
	rep(i, 1, n){
		if (ans1[i] > ans2[i]) {d = 1; break;}
		else if (ans1[i] < ans2[i]) {d = 2; break;}
	}
	if (d == -1 || d == 1) rep(i, 1, n) printf("%d ", ans1[i]);
	else rep(i, 1, n) printf("%d ", ans2[i]);
	//rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}
