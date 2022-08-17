#include <bits/stdc++.h>
#define maxr 100000
#define maxn 200015
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int
#define pii pair<int, int>
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define fi first
#define se second
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> bool read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-' && ch != EOF) ch = gc();
	if (ch == EOF) return false;
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
	return true;
}

void reads(char* s, int& len){	
	char ch = gc(); len = 0;
	while (!('a' <= ch && ch <= 'z')) ch = gc();
	while ('a' <= ch && ch <= 'z') s[++len] = ch, ch = gc();
}

int n;
int a[maxn], b[maxn];
int lea[maxn], leb[maxn];
pii sta[maxn], stb[maxn];

void process(int* v, pii* st, int* le){
	int l = 0; pii op;
	rep(i, 1, n){
		op.fi = v[i], op.se = i;
		while (l && (st[l].fi > op.fi)) op.se = st[l--].se;
		st[++l] = op;
		le[i] = op.se;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	while (read(n)){
		rep(i, 1, n) read(a[i]);
		rep(i, 1, n) read(b[i]);
		process(a, sta, lea);
		process(b, stb, leb);
		rep(i, 1, n){
			if (lea[i] != leb[i]){
				printf("%d\n", i - 1);
				goto jump;
			}
		}
		printf("%d\n", n);
		jump:;
	}
	return 0;
}
