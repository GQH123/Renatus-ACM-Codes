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

#define maxn 300200
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int last_fuck;
int nxt0, nxt1;

char s[maxn];
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		last_fuck = nxt0 = nxt1 = n + 1;
		ll res = 0;
		per(i, n, 1) {
			if (s[i] == '0') {
				bool cond0 = (nxt0 <= n && ((i & 1) ^ (nxt0 & 1)));
				bool cond1 = (nxt1 <= n && (1 ^ (i & 1) ^ (nxt1 & 1)));
				if (cond0) {
					last_fuck = min(last_fuck, nxt0);
				}
				if (cond1) {
					last_fuck = min(last_fuck, nxt1);
				}
				nxt0 = i;
			}
			else if (s[i] == '1') {
				bool cond0 = (nxt0 <= n && (1 ^ (i & 1) ^ (nxt0 & 1)));
				bool cond1 = (nxt1 <= n && ((i & 1) ^ (nxt1 & 1)));
				if (cond0) {
					last_fuck = min(last_fuck, nxt0);
				}
				if (cond1) {
					last_fuck = min(last_fuck, nxt1);
				} 
				nxt1 = i;
			}
			res += last_fuck - i;
		}
		printf("%lld\n", res);
	}
	return 0;
}

