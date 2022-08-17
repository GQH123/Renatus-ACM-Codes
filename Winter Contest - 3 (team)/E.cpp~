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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

#define maxsig 26
#define maxn 2000020

namespace SAM{
	int mxl[maxn], go[maxn][maxsig], par[maxn], siz[maxn], last = 1, ct = 1;
	bool isleaf[maxn];
	multiset<int> s;
	void extend(int ch) {
		int p = last, np = last = ++ct; isleaf[np] = 1, mxl[np] = mxl[p] + 1, siz[np] = 1;
		while (p && !go[p][ch]) go[p][ch] = np, p = par[p];
		if (p) {
			int q = go[p][ch];
			if (mxl[q] == mxl[p] + 1) {
				if (isleaf[q]) isleaf[q] = 0, s.erase(s.lower_bound(mxl[par[q]] + 1));
				par[np] = q;
				s.insert(mxl[q] + 1);
			}
			else {
				int nq = ++ct;
				if (isleaf[q]) s.erase(s.lower_bound(mxl[par[q]] + 1));
				par[nq] = par[q], par[q] = par[np] = nq, mxl[nq] = mxl[p] + 1;
				if (isleaf[q]) s.insert(mxl[par[q]] + 1);
				//if (isleaf[nq]) isleaf[nq] = 0, s.erase(s.lower_bound(mxl[par[nq]] + 1));
				s.insert(mxl[nq] + 1);
				srep(i, 0, maxsig) go[nq][i] = go[q][i];
				while (p && go[p][ch] == q) go[p][ch] = nq, p = par[p];
			}
		}else {
			if (isleaf[1]) isleaf[1] = 0, s.erase(s.lower_bound(1));
			par[np] = 1;
			s.insert(mxl[1] + 1);
		}
		printf("%d\n", *s.begin());
	}
}using namespace SAM;

char ss[maxn];
int main(){
	int l = 0; read(l);
	reads(ss);
	srep(i, 0, l) extend(ss[i] - 'a');
	return 0;
}

