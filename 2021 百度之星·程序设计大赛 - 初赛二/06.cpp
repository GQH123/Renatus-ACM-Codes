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

#define maxn 2021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 
#define mo(x) (x = x >= M ? x - M : x)

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int d[maxn], dnum[maxn];

/*
namespace D{
	int d[maxn];
	void dfs(int x, int fa) {
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			d[op] = d[x] + 1;
			dfs(op, x);
		}
	}
	int getd(){
		d[1] = 0; dfs(1, -1);
		int mxd = 0, mxd2 = -1;
		rep(i, 1, n) {
			if (d[i] > mxd) mxd = d[i], mxd2 = i;
		}
		d[mxd2] = 0; dfs(mxd2, -1);
		mxd = 0;
		rep(i, 1, n) mxd = max(mxd, d[i]);
		return mxd;
	}
}
*/

void dfs(int x, int fa) {
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		d[op] = d[x] + 1;
		dfs(op, x);
	}
}

ll ans = 0, ans2 = 0, ssum = 0;

void work(){
	int x, y;
	read(n); rep(i, 2, n) read(x, y), Add_Edge(x, y);
	
	ans = ans2 = ssum = 0;??????
	rep(i, 1, n) {
		d[i] = 0; dfs(i, -1);
		int mxd = 0;
		rep(j, 1, n) {
			dnum[d[j]]++;
			mxd = max(mxd, d[j]);
		}
		/*
		rep(j, 1, n) {
			if (d[j] == mxd && j < i) dnum[mxd]--;
		}
		*/
		if (mxd < ans) {
			rep(i, 0, mxd) dnum[i] = 0;
			continue;
		}
		if (mxd > ans) ans = mxd, ans2 = ssum = 0;
		
		ssum += dnum[mxd], mo(ssum);
		int tmp = 1;
		rep(i, 0, mxd) tmp = 1ll * tmp * dnum[i] % M; 
		ans2 += tmp, mo(ans2);
		
		rep(i, 0, mxd) dnum[i] = 0;
	}
	
	printf("%lld %lld\n", ans + 1, (ans2 + M - ssum / 2) % M);
	
	rep(i, 1, n) h[i] = 0; cnt = 1;
}


int main(){
	int T; read(T);
	while (T--) work();
	return 0;
}

