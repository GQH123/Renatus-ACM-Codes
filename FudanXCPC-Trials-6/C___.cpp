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

void exkmp(char* s, int* a, int n){
	a[0] = n; int p = 0, r = 0;
	srep(i, 1, n) {
		a[i] = (r > i) ? min(r - i, a[i - p]) : 0;
		while (i + a[i] < n && s[i + a[i]] == s[a[i]]) ++a[i];
		if (r < i + a[i]) r = i + a[i], p = i;
	}
}

char s[maxn]; int a[maxn];

int main(){
	int T; read(T);
	rep(TT, 1, T){
		clear(); 
		printf("Case %d: ", TT);
		reads(s);
		_n = n = strlen(s);
		srep(i, 0, n) s[i + n] = s[i]; s[n << 1] = '\0';
		_n <<= 1; m = 10; 
		exkmp(s, a, _n);
		int pre = 0, mid = 1, suf = 0;
		srep(i, 0, n) {
			
		}
		
		printf("%d %d %d\n", pre, mid, suf);
		
	}
	return 0;
}
