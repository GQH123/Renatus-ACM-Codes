#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
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

#define maxn 400020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

struct pii{
	int fi, se, id;
	pii(int fi, int se, int id) : fi(fi), se(se), id(id){}
	pii(){}
	bool operator < (const pii b) const{
		return id < b.id;
	}
	bool operator == (const pii b) const{
		return id == b.id;
	}
};

int n; pii p[maxn], q[maxn];
bool cmp1(pii a, pii b) {
	return a.fi < b.fi;
}
bool cmp2(pii a, pii b) {
	return a.se < b.se;
}
pii lis[maxn];
int cs = 0;
multiset<int> s;
int main(){
	int x, y;
	read(n); rep(i, 1, n) read(x, y), p[i] = q[i] = pii(x, y, i);
	sort(p + 1, p + 1 + n, cmp1);
	sort(q + 1, q + 1 + n, cmp2);
	lis[++cs] = p[1], lis[++cs] = p[2], lis[++cs] = p[n], lis[++cs] = p[n - 1];
	lis[++cs] = q[1], lis[++cs] = q[2], lis[++cs] = q[n], lis[++cs] = q[n - 1];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 1, cs) rep(j, i + 1, cs) {
		s.insert(max(abs(lis[i].fi - lis[j].fi), abs(lis[i].se - lis[j].se)));
	}
	//for (auto it: s) cerr << it << ' '; cerr << endl;
	s.erase(s.lower_bound(*s.rbegin()));
	printf("%d\n", *s.rbegin());
	return 0;
}

