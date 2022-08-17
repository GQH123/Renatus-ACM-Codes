#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define mxv 200020
#define mxc 11
#define maxr 500000 
#define rank RANK
#define isdigit(ch) ('0' <= ch && ch <= '9')
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
void reads(char* s){
	char ch = gc(); int l = 0;
	while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) s[l++] = ch, ch = gc(); s[l] = '\0';
}
template<class T> void read(T& x){
	char ch = gc(); x = 0;
	while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc();
} 

int e[mxv][mxc], f[mxv], len[mxv], v[mxv], sz;
int NEW(int tlen){
	++sz, f[sz] = 0, len[sz] = tlen;
	memset(e[sz], 0, sizeof(e[sz]));
	return sz;
}
void clear() {sz = -1; NEW(-1); NEW(0); fill(e[0], e[0] + mxc, 1);}
int add(int x, char c) {
	int y = e[x][c] ? 0 : NEW(len[x] + 1);
	while (x && !e[x][c]) e[x][c] = y, x = f[x];
	if (!x) f[y] = 1;
	else {
		int a = e[x][c];
		if (len[x] + 1 == len[a]) f[y] = a;
		else {
			int b = NEW(len[x] + 1);
			copy(e[a], e[a] + mxc, e[b]);
			f[b] = f[a], f[a] = f[y] = b;
			while (x && e[x][c] == a) e[x][c] = b, x = f[x];
	}}
	return y ? y : f[y]; 
}
void sort(){
	vector<int> que;
	static int c[mxv];
	fill(c, c + sz + 1, 0);
	for (int i = sz; i; --i) ++c[len[i]];
	partial_sum(c, c + sz + 1, c);
	que.resize(sz);
	for (int i = sz; i; --i) que[--c[len[i]]] = i;
	per(i, sz, 0) {
		f[
	}
}

char s[mxv];

int n, m, _n;

inline int get(int x){
	if (!x) return 0;
	return (len[f[x]] + 1 <= n && n <= len[x]) ? 1 : 0;
}

int main(){
	int T; read(T);
	rep(TT, 1, T){
		clear(); 
		printf("Case %d: ", TT);
		reads(s);
		_n = n = strlen(s);
		srep(i, 0, n) s[i + n] = s[i]; s[n << 1] = '\0';
		_n <<= 1; m = 10; 
		int last = 1;
		srep(i, 0, _n) last = add(last, s[i] - '0');   
		
		int x = 1, pre = 0, mid = 1, suf = 0;
		srep(i, 0, n) {
			rep(j, 0, 9) {
				if (s[i] - '0' > j) pre += get(e[x][j]);
				if (s[i] - '0' < j) suf += get(e[x][j]);
			}
			x = e[x][s[i] - '0'];
		}
		printf("%d %d %d\n", pre, mid, suf);
		
	}
	return 0;
}
