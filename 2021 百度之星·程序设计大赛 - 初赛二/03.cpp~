#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('0' <= ch && ch <= '1')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 2021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, s, ufs[maxn], siz[maxn], deg[maxn];

int find_root(int x) {
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
void merge(int x, int y) {
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ufs[x] = y;
	siz[y] += siz[x];
}

char t[maxn];
void work(){
	read(n, s); rep(i, 1, n) ufs[i] = i, siz[i] = 1, deg[i] = 0;
	int num = 0;
	rep(i, 2, n) {
		reads(t + 1);
		rep(j, 1, i - 1) {
			if (t[j] == '0') deg[i]++, deg[j]++, merge(i, j), num++;
		}
	}
	int odd = 0;
	rep(i, 1, n) {
		if (deg[i] & 1) {
			odd++; 
		}
	}
	if (odd > 2) {puts("-1"); return;}
	if (odd && deg[s] % 2 == 0) {puts("-1"); return;}
	int ct = 0;
	rep(i, 1, n) {
		if (ufs[i] == i) {
			if (siz[i] > 1) ct++;
		}
	}
	if (siz[find_root(s)] > 1) ct--;
	
	printf("%d\n", (ct << 1) + num);
}

int main(){
	int T; read(T);
	while (T--){
		work();
	}
	return 0;
}

