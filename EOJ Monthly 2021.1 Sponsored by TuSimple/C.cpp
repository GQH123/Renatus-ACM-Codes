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
    #define isletter(ch) ('A' <= ch && ch <= 'Z')
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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define ll long long int 

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
stack<int> init;
stack<int> st;
int lis[maxn];
int d[maxn];
int n, m;
int dfs(int x, int fa){
	bool f = 0;
	d[x] = -1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		f = 1;
		d[x] = max(d[x], dfs(op, x) + 1);
	}
	if (!f) d[x] = 1;
	return d[x];
}
int num[maxn];
int main(){
	int x, y;
	read(n, m);
	rep(i, 2, n) read(x), read(y), Add_Edge(x, y); int dep = dfs(1, -1);
	rep(i, 1, n) num[d[i]]++;
	per(i, dep, 1) init.push(num[i]);
	char op[10];
	rep(i, 1, m) {
		reads(op);
		if (op[0] == 'D') {
			if (st.empty()) init.pop();
			else st.pop();
		}
		else read(x), st.push(x);
	}
	int last = init.top(); init.pop(); int sum = last; while (!init.empty()) sum += init.top(), sum %= M, init.pop();
	int ct = st.size(), _ct = ct;
	while (!st.empty()) lis[ct--] = st.top(), st.pop();
	rep(i, 1, _ct) {
		sum += 1ll * last * lis[i] % M, sum %= M;
		last = 1ll * last * lis[i] % M;
	}
	/*
	while (!st.empty()) {
		sum += 1ll * last * st.top();
		//res = 1ll * res * st.top() % M, st.pop();
	}
	*/
	write(sum);
	return 0;
}

