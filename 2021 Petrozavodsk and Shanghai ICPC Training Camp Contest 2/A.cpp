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

#define maxn 2020
#define maxm 12
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
int p[maxm][maxn];
struct ele{
	int num[maxm];
	bool operator < (const ele b) const{
		rep(i, 1, m) if (num[i] != b.num[i]) return num[i] < b.num[i];
		return false;
	}
}now;
set<ele> s;

bool vis[maxn];
set<int> res;
void DFS(int pos){
	if (pos == m + 1) return;
	if (s.count(now)) return;
	s.insert(now);
	ele _now = now;
	rep(i, 1, m) {
		if (!now.num[i]) continue;
		res.insert(p[i][now.num[i]]);
		vis[p[i][now.num[i]]] = 1;
		now.num[i] = 0;
		rep(j, 1, m) {
			while (now.num[j] && vis[p[j][now.num[j]]]) now.num[j]++;
		}
		DFS(pos + 1);
		now = _now;
		vis[p[i][now.num[i]]] = 0; 
	}
}

int main(){
	read(n, m);
	rep(i, 1, m) rep(j, 1, n) read(p[i][j]);
	srep(i, 0, maxm) now.num[i] = 0;
	rep(i, 1, m) now.num[i] = 1;
	DFS(1);
	printf("%d\n", res.size());
	for (auto it : res) {
		printf("%d ", it);
	}
	return 0;
}

