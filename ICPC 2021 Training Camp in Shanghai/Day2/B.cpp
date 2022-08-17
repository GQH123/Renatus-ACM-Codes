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

#define maxn 1000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, p, q;
int que[maxn], head = 0, tail = 0;
int in[maxn], out[maxn];
set<int> to[maxn], fr[maxn];

set<pii> e;

int res[maxn], cs = 0;

void recover(){
	rep(i, 1, n) in[i] = out[i] = que[i] = res[i] = 0, to[i].clear(), fr[i].clear();
	cs = head = tail = 0; 
	e.clear();
}
int main(){
	int T; read(T);
	while (T--){
		read(n, p, q);
		srep(i, 0, n) {
			if (i + p < n) out[i]++, in[i + p]++, to[i].insert(i + p), fr[i + p].insert(i);
			if (i - q >= 0) out[i]++, in[i - q]++, to[i].insert(i - q), fr[i - q].insert(i);
		}
		srep(i, 0, n) {
			if (in[i] == 1 || out[i] == 1) que[++head] = i;
		}
		while (head > tail){
			int x = que[++tail];
			if (out[x] == 1) {
				int op = *to[x].begin();
				assert(to[x].size() == 1);
				out[x]--;
				in[op]--;
				e.insert(pii(x, op));
				to[x].erase(op);
				fr[op].erase(x);
				if (in[op] == 1) que[++head] = op;
			}
			if (in[x] == 1) {
				int op = *fr[x].begin();
				assert(fr[x].size() == 1);
				in[x]--;
				out[op]--;
				e.insert(pii(op, x));
				to[op].erase(x);
				fr[x].erase(op);
				if (out[op] == 1) que[++head] = op;
			}
		}
		/*
		for (auto it : e) {
			printf("%d %d\n", it.fi, it.se);
		}
		*/
		int now = -1; pii op = pii(-1, -1);
		if (e.size() < n) {
			puts("-1");
			goto done;
		}
		op = *e.begin();
		res[++cs] = op.fi, res[++cs] = op.se;
		now = op.se;
		e.erase(op);
		rep(i, 1, n - 2) {
			op = *e.lower_bound(pii(now, -1));
			if (op.fi != now) break;
			res[++cs] = op.se;
			now = op.se;
			e.erase(op);
		}
		if (cs < n) {
			puts("-1");
			goto done;
		}
		rep(i, 1, n) printf("%d ", res[i]); printf("\n");
		done: recover();
	}
	
	return 0;
}

