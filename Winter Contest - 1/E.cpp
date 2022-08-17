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

#define maxn 10
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n;
struct follow{
	int atk, hp;
	follow(int atk, int hp) : atk(atk), hp(hp){}
	follow(){}
}lis[maxn];

int per[maxn];
long double p[maxn];
bool alive[maxn];
void dfs(int pos, long double eff) {
	if (pos == n + 1) {
		rep(i, 1, n) if (alive[i]) p[i] += eff; 
		return;
	}
	int x = per[pos];
	if (!alive[x]) {
		dfs(pos + 1, eff);
		return;
	}
	long double _eff = 0; bool hav = 0;
	rep(i, 1, n) {
		if (!alive[i] || i == x) continue;
		hav = 1;
		_eff += 1;
	}
	if (!hav) {
		dfs(pos + 1, eff);
		return;
	}
	_eff = 1.0 / _eff;
	rep(i, 1, n) {
		if (!alive[i] || x == i) continue;
		lis[x].hp -= lis[i].atk;
		lis[i].hp -= lis[x].atk;
		if (lis[x].hp <= 0) alive[x] = false;
		if (lis[i].hp <= 0) alive[i] = false;
		dfs(pos + 1, eff * _eff);
		lis[x].hp += lis[i].atk;
		lis[i].hp += lis[x].atk;
		alive[x] = alive[i] = true;
	}
}
int main(){
	read(n); rep(i, 1, n) per[i] = i, alive[i] = true;
	rep(i, 1, n) read(lis[i].atk, lis[i].hp);
	long double eff = 1.0; rep(i, 1, n) eff = i * eff; eff = 1.0 / eff;
	do{	
		//rep(i, 1, n) cerr << per[i] << ' '; cerr << endl;
		dfs(1, eff);
	}while (next_permutation(per + 1, per + 1 + n));
	rep(i, 1, n) printf("%.20Lf\n", p[i]);
	return 0;
}

