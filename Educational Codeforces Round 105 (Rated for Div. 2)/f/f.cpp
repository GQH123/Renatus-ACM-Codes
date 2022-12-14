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

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn], cur[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
int a, b;
vector<int> lisa, lisb, lis[maxn];

int res[maxn];
bool vis[maxn << 1];
int cs = 0;
void dfs(int x) {
	int& i = cur[x];
	while (i) {
		if (vis[i] || vis[i ^ 1]) {
			i = e[i].next;
			continue;
		}
		int op = e[i].to;
		int _i = i;
		vis[_i] = vis[_i ^ 1] = 1;
		i = e[i].next;
		dfs(op);  
		res[++cs] = op;
	}
}

void dfs_(int x) {
	int& i = cur[x];
	while (i) {
		if (vis[i] || vis[i ^ 1]) {
			i = e[i].next;
			continue;
		}
		int op = e[i].to;
		if (x == a && (deg[op] & 1)) {
			i = e[i].next;
			continue;
		}
		if ((deg[x] & 1) && op == a) {
			i = e[i].next;
			continue;
		}
		int _i = i;
		vis[_i] = vis[_i ^ 1] = 1;
		i = e[i].next;
		dfs_(op);  
		res[++cs] = op;
	}
}
/*
void _dfs(int x, int rt) {
	int& i = cur[x];
	while (i) {
		if (vis[i] || vis[i ^ 1]) {
			i = e[i].next;
			continue;
		}
		int op = e[i].to;
		if ((x == rt) && (deg[op] & 1)) {
			i = e[i].next;
			continue;
		}
		if ((deg[x] & 1) && (op == rt)) {
			i = e[i].next;
			continue;
		}
		int _i = i;
		vis[_i] = vis[_i ^ 1] = 1;
		i = e[i].next;
		_dfs(op, rt);  
		res[++cs] = op;
	}
} 
*/
set<int> _lis;
int main(){
	read(n, m);
	int x, y;
	rep(i, 1, m) {
		read(x, y), Add_Edge(x, y);  
	}
	rep(i, 1, n) cur[i] = h[i];
	int num = 0;
	rep(i, 1, n) {
		if (deg[i] & 1) {
			num++;
			if (!a) a = i;
			else if (!b) b = i;
		}
	}
	if (!num) {
		dfs(1); res[++cs] = 1;
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", res[i]);
		return 0;
	}
	if (num == 2) { 
		dfs(a); res[++cs] = a;
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", res[i]);
		return 0;
	}
	a = b = 0;
	rep(i, 1, n) {
		if (deg[i] & 1) { 
			erep(x, i) {
				int op = e[x].to; 
				lis[op].pb(i);
			}
		}
	}
	rep(i, 1, n) {
		if (lis[i].size() == num) {
			a = i;
			//_dfs(i, i);
			dfs_(a);
			res[++cs] = i;
			reverse(res + 1, res + 1 + cs);
			res[++cs] = -1;
			for (auto it : lis[i]) {
				res[++cs] = it, res[++cs] = i;
			} 
			printf("%d\n", cs);
			rep(i, 1, cs) printf("%d ", res[i]);
			return 0;
		}
	}
	rep(i, 1, n) {
		if (lis[i].size() == num - 1) {
			if (deg[i] & 1) {
				a = i;  
				dfs_(a); res[++cs] = a;
				reverse(res + 1, res + 1 + cs);
				res[++cs] = -1;
				for (auto it : lis[a]) {
					res[++cs] = it, res[++cs] = a;
				}
				printf("%d\n", cs);
				rep(i, 1, cs) printf("%d ", res[i]);
				return 0;
			}
			else {
				a = i; 
				for (auto it : lis[a]) 
					_lis.insert(it);
				rep(j, 1, n) { 
					if (deg[j] & 1) {	
						if (j == a) continue;
						if (!_lis.count(j)) {b = j; break;}
					}
				}
				if (b) { dfs_(b); res[++cs] = b; } else res[++cs] = a;
				reverse(res + 1, res + 1 + cs);
				res[++cs] = -1;
				for (auto it : lis[a]) {
					res[++cs] = it, res[++cs] = a;
				}
				printf("%d\n", cs);
				rep(i, 1, cs) printf("%d ", res[i]);
				return 0;
			}
		}
	}
	rep(i, 1, n) {
		if (lis[i].size() == num - 2 && (deg[i] & 1)) {
			a = i; 
			for (auto it : lis[i]) 
				_lis.insert(it);
			rep(j, 1, n) { 
				if (deg[j] & 1) {	
					if (j == i) continue;
					if (!_lis.count(j)) {b = j; break;}
				}
			}
			if (b) { dfs_(b); res[++cs] = b; } else res[++cs] = a;
			reverse(res + 1, res + 1 + cs);
			res[++cs] = -1;
			for (auto it : lis[a]) {
				res[++cs] = it, res[++cs] = a;
			}
			printf("%d\n", cs);
			rep(i, 1, cs) printf("%d ", res[i]);
			return 0;
		}
	}
	puts("0"); 
	return 0; 
}

