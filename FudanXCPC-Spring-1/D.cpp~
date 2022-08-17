#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 60020
#define maxm
#define maxs 120
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0');return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]);
}

struct ele{
	int id, f;
	ele(int id, int f) : id(id), f(f){}
	ele(){}
	bool operator < (const ele b) const{
		return (f == b.f) ? id < b.id : f > b.f;
	}
};
int n;
vector<ele> s[maxs];
int ptr[maxs];
int lis[maxn], cs = 0;

void recover(){
	rep(i, 1, cs) s[lis[i]].clear(), ptr[lis[i]] = 0;
	cs = 0;
}
int main(){
	
		freopen("D.in", "r", stdin);
		
		//Case #c:
	int T, x, y;
	read(T);
	rep(TT, 1, T){
		printf("Case #%d:\n", TT);
		read(n);
		rep(i, 1, n) read(x), read(y), s[y].pb(ele(i, x)), lis[++cs] = y;
		sort(lis + 1, lis + 1 + cs);
		cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
		rep(i, 1, cs) {
			int x = lis[i];
			sort(s[x].begin(), s[x].end());
		}
		srep(num, 0, n){
			int mx = 0, mi = n + 1, fs = -1;
			rep(i, 1, cs){
				int x = lis[i];
				if (ptr[x] == s[x].size()) continue;
				int d = x * num + s[x][ptr[x]].f;
				if (d > mx) mx = d, mi = s[x][ptr[x]].id, fs = x; 
				else if (d == mx && s[x][ptr[x]].id < mi) mi = s[x][ptr[x]].id, fs = x; 
			}
			ptr[fs]++;
			write(mi);
			if (num != n - 1) pc(' '); 
		}
		recover();
		pc('\n');
	} 
	return 0;
}

