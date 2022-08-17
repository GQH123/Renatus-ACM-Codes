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

#define maxn 100020
#define maxm
#define maxs 500020
#define sigma 26
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define id(x) (x - 'a')

int ch[maxs][sigma];
int siz[maxs];
int val[maxs];
int ct = 0;
void insert(char* s, int n, int id) {
	int now = 0;
	//siz[now]++;
	srep(i, 0, n) {
		if (!ch[now][id(s[i])]) ch[now][id(s[i])] = ++ct;
		now = ch[now][id(s[i])];
		siz[now]++;
	}
	val[now] = id;
}

int v[maxn][sigma][sigma], sml[maxn];
int num[sigma][sigma], pas = 0;
void dfs(int x) {
	if (val[x]) {
		pas++;
		rep(a, 0, 25) rep(b, 0, 25) v[val[x]][a][b] = num[a][b];
		sml[val[x]] = pas;
	}
	/*
	rep(i, 0, 25) {
		int nu = siz[ch[x][i]];
		rep(j, 0, 25) num[i][j] += nu; 
	}
	*/
	rep(i, 0, 25) {
		if (!ch[x][i]) continue;
		rep(j, 0, 25) num[j][i] += siz[ch[x][j]];
		dfs(ch[x][i]);
		rep(j, 0, 25) num[j][i] -= siz[ch[x][j]];
	}
	if (val[x]) pas--;
}

char per[30];
int pos[30];
/*
void getK(int now, int k) {
	srep(i, 0, 25) {
		int nxt = ch[now][id(per[i])];
		if (k > siz[nxt]) k -= siz[nxt];
		else putchar(per[i]), now = nxt;
	}
	putchar('\n');
}
*/
int n, m, k;
char s[maxs];
int main(){
	read(n); int l = 0;
	rep(i, 1, n) l = reads(s), insert(s, l, i); 
	//cerr << ct << endl;
	dfs(0);
	read(m);
	rep(i, 1, m) {
		read(k), reads(per);
		rep(j, 0, 25) pos[per[j] - 'a'] = j;
		int ans = sml[k];
		rep(a, 0, 25) rep(b, 0, 25) if (pos[a] < pos[b]) ans += v[k][a][b]; 
		write(ans);
	}
	return 0;
}

