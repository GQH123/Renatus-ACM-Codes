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

#define maxn 800022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int head = 0;
int path[maxn];
int cs = 0;
int le[maxn], ri[maxn];

void init(){
	int realn = head * 2 + 1;
	//cout << realn << endl;
	int n = head * 2 + 1;
	per(i, head, 1) {
		int l = (i - 1) * 4, r = i * 4 - 1;
		int str = n * n - 1, stl = n * n - n + 2;
		per(j, 3, 0) {
			le[l + j] = stl;
			ri[l + j] = str;
			
			stl -= (n - 1);
			str -= (n - 1);
			
			le[l + j] = realn * realn - le[l + j] + 1;
			ri[l + j] = realn * realn - ri[l + j] + 1;
			
			swap(le[l + j], ri[l + j]);
			
			//cout << l + j << ' ' << le[l + j] << ' ' << ri[l + j] << endl;
		}
		n -= 2;
	}
}

bool dep(int x) {
	cs = 0;
	per(i, head, 1) {
		int l = (i - 1) * 4, r = i * 4 - 1;
		if (x > r) {
			path[++cs] = r;
			x -= r;
		}
		else if (x < l) {
			continue;
		}
		else {
			path[++cs] = x;
			return true;
		}
	}
	if (x > 0) return false; 
	else return true;
}

pii out[maxn];
int co = 0;

int n, k;
int main(){
	int T; read(T);
	rep(__, 1, T){
		read(n, k);
		int rest = n * n - 1 - k;
		if (rest & 1) {
			printf("Case #%d: IMPOSSIBLE\n", __);
			continue;
		}
		rest >>= 1;
		head = (n - 1) / 2;
		
		if (!dep(rest)) {
			printf("Case #%d: IMPOSSIBLE\n", __);
			continue;
		}
		
		init();
		
		co = 0;
		int now = 1;
		//rep(i, 1, cs) path[i] = path[i] * 2 + 1; 
		rep(i, 1, cs) {
			if (now < le[path[i]]) {
				now = le[path[i]];
			}
			else {
				assert(now <= ri[path[i]]);
			}
			int step = path[i] * 2 + 1;
			out[++co] = pii(now, now + step);
		}
		printf("Case #%d: %d\n", __, co); //printf("\n");
		rep(i, 1, co) printf("%d %d\n", out[i].fi, out[i].se);
	}
	return 0;
}

