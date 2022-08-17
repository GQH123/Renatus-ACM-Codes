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

#define maxn 122
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int m;

struct ele{
	int v[maxn];
	ele(){memset(v, 0, sizeof(v));}
	void operator = (const ele b) {
		rep(j, 1, m) v[j] = b.v[j];
	}
	void clear(){
		memset(v, 0, sizeof(v));
	}
	int sum(){
		int ans = 0;
		rep(j, 1, m) ans += v[j];
		return ans;
	}
}now, a[maxn];

ele operator - (ele a, ele b) {
	ele c;
	rep(j, 1, m) c.v[j] = a.v[j] - b.v[j];
	return c;
}

ele operator + (ele a, ele b) {
	ele c;
	rep(j, 1, m) c.v[j] = a.v[j] + b.v[j];
	return c;
}

stack<ele> g;

bool judge(ele now, ele a) {
	rep(j, 1, m) {
		if (now.v[j] > a.v[j]) return false;
	}
	return true;
}

int n;

int main(){
	int T; read(T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		read(n, m);
		rep(i, 1, n) rep(j, 1, m) read(a[i].v[j]);
		
		ll sum = 0;
		rep(i, 1, n) {
			ele op;
			while (!judge(now, a[i])) {
				op = g.top(); g.pop();
				sum += op.sum();
				now = now - op;
			}
			now = now + op;
			sum -= op.sum();
			
			rep(j, 1, m) {
				if (now.v[j] > a[i].v[j]) {
					op.v[j] -= (now.v[j] - a[i].v[j]);
					sum += (now.v[j] - a[i].v[j]);
					now.v[j] = a[i].v[j];
					assert(op.v[j] >= 0);
				}
			}
			if (op.sum() > 0) g.push(op);
			
			op = a[i] - now;
			
			//rep(j, 1, m) printf("%d ", a[i].v[j]); printf("\n");
			//rep(j, 1, m) printf("%d ", now.v[j]); printf("\n");
			//rep(j, 1, m) printf("%d ", op.v[j]); printf("\n");
			
			sum += op.sum();
			if (op.sum() > 0) g.push(op);
			now = a[i];
		}
		sum += now.sum();
		printf("%lld\n", sum);
		
		while (!g.empty()) g.pop();
		rep(i, 1, n) a[i].clear();
		n = m = 0;
		now.clear();
	}
	return 0;
}

