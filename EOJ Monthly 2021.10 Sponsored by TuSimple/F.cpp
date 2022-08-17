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

#define maxn 30021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int lim = 0;
int ct = 0;
int cnum = 0;
int q(int x, int y) {	
	if (ct == lim) {cerr << cnum << endl; assert(false);}
	ct++;
	int res;
	cout << '?' << ' ' << x << ' ' << y << endl; //fflush(stdout);
	cin >> res;
	return res;
}

#define bound 10

int out[maxn];
set<pii> hav;

int vis[maxn];
int main(){
	srand(131291230);
	int n;
	cin >> n;
	
	lim = 6 * n / 5;
	
	int p = -1, v = -1;
	while (1) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		if (x == y || hav.count(pii(x, y))) continue;
		hav.insert(pii(x, y));
		int z = q(x, y);
		cnum++;
		
		if (z > n - n / bound) {
			p = x;
			v = z;
			break;
		}
	}
	
	rep(i, 1, n) {
		if (i == p) {
			out[i] = v;
			continue;
		}
		out[i] = q(i, p);
		if (out[i] <= n % v) {
			if (vis[out[i]] == 1) {out[i] += v; continue;}
			else if (vis[out[i]] == 0) {
				int rd = q(p, i);
				if (rd == v) {
					vis[out[i]] = 2;
					out[i] += v;
				}
				else vis[out[i]] = 1;
			}
		}
	}
	
	cout << '!';
	rep(i, 1, n) cout << ' ' << out[i];
	cout << endl;
	//fflush(stdout);
	
	return 0;
}

