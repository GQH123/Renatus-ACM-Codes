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

#define maxn 520
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int lis[maxn * maxn], cs = 0;
int n, a[maxn];


//#define debug
void update(int p) {
	lis[++cs] = p;
	swap(a[p], a[p + 1]);
	
	#ifdef debug
		rep(i, 1, n) cerr << a[i] << ' '; cerr << endl;
	#endif
}

int main(){
	int T; read(T);
	while (T--){
		read(n); rep(i, 1, n) read(a[i]);
		if (n <= 3) {
			while (1) {
				bool ok = 1;
				rep(i, 1, n) {
					if (a[i] != i) {
						ok = 0;
						break;
					}
				}
				if (ok) break;
				
				if ((cs + 1) & 1) {
					update(1);
				}
				else {
					update(2);
				}
			}
			printf("%d\n", cs);
			rep(i, 1, cs) printf("%d ", lis[i]); printf("\n");
			cs = 0;
			continue;
		}
		int ptr = 0; while (ptr <= n && a[ptr] == ptr) ptr++;
		while (ptr <= n) {
			int f = -1;
			rep(i, ptr, n) {
				if (a[i] == ptr) {
					f = i;
					break;
				}
			}
			assert(f != 1 && f != -1);
			if (((f - 1) & 1) == ((cs + 1) & 1)) {
				while (a[ptr] != ptr) {
					update(f - 1);
					f--;
				}
			}
			else {
				if (f < n) {
					update(f);
					update(f - 1);
					while (a[ptr] != ptr) {
						update(f);
						f--;
					}
				}
				else {
					if (ptr - 1 < f - 2) {
						update(f - 2);
						while (a[ptr] != ptr) {
							update(f - 1);
							f--;
						}
					}
					else {
						update(f - 2);
						update(f - 1);
						update(f - 2);
						update(f - 1);
						update(f - 2);
						assert(a[ptr] == ptr);
					}
				}
			}
			
			while (ptr <= n && a[ptr] == ptr) ptr++;
		}
		
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", lis[i]); printf("\n");
		cs = 0;
	}
	return 0;
}

