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

#define maxn 1000020
//#define maxn 120
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int pri[maxn], cp = 0;
bool vis[maxn];

int lis[maxn], _lis[maxn], cs = 0;
vector<int> tab[maxn];
int T = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) pri[++cp] = i;
		rep(j, 1, cp) {
			if (i * pri[j] >= maxn) break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	srep(i, 1, maxn) lis[i] = i; cs = maxn - 1;
	while (cs) {
		++T;
		int _cs = 0;
		rep(j, 1, cs) {
			if (vis[j]) {
				_lis[++_cs] = lis[j];
			}
			else {
				tab[T].pb(lis[j]);
			}
		}
		/*
		srep(i, 0, tab[T].size()) {
			cerr << tab[T][i] << ' ';
		}cerr << endl;
		*/
		rep(i, 1, _cs) lis[i] = _lis[i];
		cs = _cs;
	}
}

int main(){
	int m, t, n, k; read(m);
	init();
	while (m--){
		read(t, n, k);
		if (t == 1) {
			int res = 0;
			rep(i, 1, T){
				int num = upper_bound(tab[i].begin(), tab[i].end(), n) - tab[i].begin();
				int pos = lower_bound(tab[i].begin(), tab[i].end(), k) - tab[i].begin();
				if (pos < tab[i].size() && tab[i][pos] == k) {
					res += pos + 1;
					printf("%d\n", res);
					break;
				}
				else res += num;
			}
		}
		else {
			int res = 0;
			rep(i, 1, T){
				int num = upper_bound(tab[i].begin(), tab[i].end(), n) - tab[i].begin();
				int pos = lower_bound(tab[i].begin(), tab[i].end(), k) - tab[i].begin();
				if (k <= num) {
					printf("%d\n", tab[i][k - 1]);
					break;
				}
				else k -= num;
			} 
		}
	}
	return 0;
}

