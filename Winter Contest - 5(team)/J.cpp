#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
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
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
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
    #define isletter(ch) ('a' <= ch && ch <= 'z')
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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int a[maxn], b[maxn];
vector<int> res[maxn];
int main(){
	int n, m; read(n, m);
	int fa = -1, za = -1;
	rep(i, 1, n) {
		read(a[i]);
		if (a[i]) {
			if (fa != -1) {
				printf("No\n");
				return 0;
			}
			fa = i;
		}
		else za = i;
	}
	int fb = -1, zb = -1;
	rep(i, 1, m) {
		read(b[i]);
		if (b[i]) {
			if (fb != -1) {
				printf("No\n");
				return 0;
			}
			fb = i;
		}
		else zb = i;
	}
	if (fa == -1 || fb == -1) {
		printf("No\n");
		return 0;
	}
	if (a[fa] > 1 && b[fb] > 1) {
		printf("No\n");
		return 0;
	}
	rep(i, 1, n) {res[i].pb(-1); rep(j, 1, m) res[i].pb(-1);}
	res[fa][fb] = 0;
	if (n * m == 1) {
		if (a[fa] != 1 || b[fb] != 1) {
			printf("No\n");
			return 0;
		}
		printf("Yes\n");
		rep(i, 1, n) { rep(j, 1, m) printf("%d ", res[i][j]); printf("\n"); }
		return 0;
	}
	if (n == 1) {
		if (a[fa] != m || b[fb] != 1) {
			printf("No\n");
			return 0;
		}
		printf("Yes\n");
		int ptr = 0;
		rep(i, 1, n) { 
			rep(j, 1, m) { 
				if (res[i][j] == -1) res[i][j] = ++ptr;
				printf("%d ", res[i][j]); 
			} 
			printf("\n"); 
		} 
		return 0;
	}
	if (m == 1) {
		if (a[fa] != 1 || b[fb] != n) {
			printf("No\n");
			return 0;
		}
		printf("Yes\n");
		int ptr = 0;
		rep(i, 1, n) { 
			rep(j, 1, m) { 
				if (res[i][j] == -1) res[i][j] = ++ptr;
				printf("%d ", res[i][j]); 
			} 
			printf("\n"); 
		} 
		return 0;
	}
	
	if (a[fa] == 1 && b[fb] == 1) {
		res[za][zb] = 1;
		printf("Yes\n");
		int ptr = 1; 
		rep(i, 1, n) { 
			rep(j, 1, m) { 
				if (res[i][j] == -1) res[i][j] = ++ptr;
				printf("%d ", res[i][j]); 
			} 
			printf("\n"); 
		} 
		return 0;
	}
	if (a[fa] == 1) {
		int ptr = 1;
		rep(i, 1, n){ 
			if (ptr == b[fb]) break;
			if (res[i][fb] == -1) res[i][fb] = ptr++; 
		}
		if (ptr != b[fb]) {
			printf("No\n");
			return 0;
		}
		res[fa][zb] = ptr++;
		
		printf("Yes\n");
		rep(i, 1, n) { 
			rep(j, 1, m) {
				if (res[i][j] == -1) res[i][j] = ptr++;
				printf("%d ", res[i][j]); 
			}
			printf("\n"); 
		} 
		return 0;
	}
	else {
		int ptr = 1;
		rep(j, 1, m){ 
			if (ptr == a[fa]) break;
			if (res[fa][j] == -1) res[fa][j] = ptr++; 
		}
		if (ptr != a[fa]) {
			printf("No\n");
			return 0;
		}
		res[za][fb] = ptr++;
		
		printf("Yes\n");
		rep(i, 1, n) { 
			rep(j, 1, m) {
				if (res[i][j] == -1) res[i][j] = ptr++;
				printf("%d ", res[i][j]); 
			}
			printf("\n"); 
		} 
		return 0;
	}
	return 0;
}

