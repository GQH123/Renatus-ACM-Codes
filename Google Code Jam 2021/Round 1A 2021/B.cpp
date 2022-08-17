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

#define maxn 2020
#define maxm
#define maxs 500
#define maxb
#define inf 
#define eps
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 

int pri[maxs], cp = 0, pid[maxs];
bool vis[maxs];
void init(){
	int sum = 0;
	srep(i, 2, maxs) {
		if (!vis[i]) pri[++cp] = i, sum += i, pid[i] = cp;
		rep(j, 1, cp) {
			if (i * pri[j] >= maxs) break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	cerr << sum << endl;
}

int num[maxn];
bool dep(ll res, ll x) { 
	rep(i, 1, cp) {  
		if (x % pri[i] == 0) { 
			int nnum = 0;
			while (x % pri[i] == 0) { 
				nnum++;
				x /= pri[i];
			} 
			if (nnum > num[i]) return false; 
			res -= nnum * pri[i];
		}  
	}
	if (x > 1) return false;
	return !res;
} 

ll p[maxn];
#define bound 10000
int main(){
	init();
	int T, n; read(T);
	rep(TT, 1, T){
    	printf("Case #%d: ", TT);
    	ll x, y;
    	rep(i, 0, cp) num[i] = 0;
    	ll sum = 0;
		read(n); rep(i, 1, n) read(x, y), num[pid[x]] = y, sum += x * y; 
		for (ll i = sum; i >= sum - bound; i--) {
			if (!i) break;
			if (dep(sum - i, i)) {
				printf("%lld\n", i);
				goto done;
			}
		}
		printf("0\n");
		done:;
	}
	return 0;
}

