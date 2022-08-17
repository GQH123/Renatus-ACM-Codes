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

#define maxn 500020
#define maxsig 26
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

struct Trie{
	int ch[maxn][maxsig];
	int val[maxn];
	int ct = 0;
	int cnt[maxn];
	void insert(char* s, int n, int id, int& rid) {
		int now = 0;
		cnt[now]++;
		srep(i, 0, n) {
			if (!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++ct;
			now = ch[now][s[i] - 'a'];
			cnt[now]++;
		} 
		val[now] = id;
		rid = now;
	}
	int get(char* s, int n) {	
		int now = 0;
		srep(i, 0, n) {
			if (!ch[now][s[i] - 'a']) return 0;
			now = ch[now][s[i] - 'a'];
		}
		return now;
	}
	int dfs[maxn], rdfs[maxn], ti = 0, siz[maxn];
	void Dfs(int x){
		dfs[x] = ++ti;
		rdfs[ti] = x;
		siz[x] = 1;
		srep(i, 0, maxsig){
			int op = ch[x][i];
			if (!op) continue;
			Dfs(op);
			siz[x] += siz[op];
		}
	}
}P, S;

int sid[maxn], pid[maxn];

struct ele{
	int x, v, l, r, id;
	ele(int x, int v, int l, int r, int id) : x(x), v(v), l(l), r(r), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return x < b.x;
	}
}lis[maxn << 1];
int cs = 0;

int c[maxn];
int get(int x){
	int res = 0;
	while (x){
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}
void mod(int x, int v){
	while (x <= S.ti) {
		c[x] += v;
		x += lowbit(x);
	}
}
int ans[maxn];
int Pans[maxn];
int Sans[maxn];
char s[maxn];

pii vlis[maxn]; int cv = 0;
int main(){
	int n; read(n);
	rep(i, 1, n) {
		int l = reads(s);
		P.insert(s, l, i, pid[i]);
		reverse(s, s + l);
		S.insert(s, l, i, sid[i]);
	}
	P.Dfs(0), S.Dfs(0);
	rep(i, 1, n) vlis[++cv] = pii(P.dfs[pid[i]], i);
	sort(vlis + 1, vlis + 1 + cv);
	
	int m;
	read(m);
	rep(i, 1, m){
		int l = reads(s);
		int resp = P.get(s, l);
		int lp = P.dfs[resp], rp = P.dfs[resp] + P.siz[resp] - 1;
		
		
		l = reads(s); reverse(s, s + l);
		int ress = S.get(s, l);
		int ls = S.dfs[ress], rs = S.dfs[ress] + S.siz[ress] - 1;
		
		
			if (resp) Pans[i] += P.cnt[resp];
			if (ress) Sans[i] += S.cnt[ress];
			if (ress && resp) lis[++cs] = ele(lp, 1, ls, rs, i), lis[++cs] = ele(rp + 1, -1, ls, rs, i);
	}
	
	sort(lis + 1, lis + 1 + cs);
	
	int ptr = 1;
	rep(i, 1, n){
		while (ptr <= cs && lis[ptr].x <= vlis[i].fi) {
			if (lis[ptr].v == 1) {
				ans[lis[ptr].id] -= (get(lis[ptr].r) - get(lis[ptr].l - 1));
			}
			else {
				ans[lis[ptr].id] += (get(lis[ptr].r) - get(lis[ptr].l - 1));
			}
			ptr++;
		}
		mod(S.dfs[sid[vlis[i].se]], 1);
	}
	while (ptr <= cs) {
		if (lis[ptr].v == 1) {
			ans[lis[ptr].id] -= (get(lis[ptr].r) - get(lis[ptr].l - 1));
		}
		else {
			ans[lis[ptr].id] += (get(lis[ptr].r) - get(lis[ptr].l - 1));
		}
		ptr++;
	}
	
	rep(i, 1, m) {
		printf("%d\n", Pans[i] + Sans[i] - ans[i]);
	}
	return 0;
}

