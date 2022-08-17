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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

namespace BSGS{ // a^x = r mod M
	int power(int x, int y) {
		int ans = 1, con = x;
		while (y){
			if (y & 1) ans = 1ll * ans * con % M;
			y >>= 1;
			con = 1ll * con * con % M;
		}
		return ans;
	}
	int getinv(int x) {
		return power(x, M - 2);
	}
	
	const int d = round(sqrt(M));
	int block;
	unordered_map<int, int> tab;
	
	void init(int a){
		int v = 1;
		srep(i, 0, d) {
			if (!tab.count(v)) tab[v] = i;
			v = 1ll * v * a % M;
		}
		block = getinv(v);
	}
	int query(int r){	
		if (!r) return M + 1;
		int ans = 0;
		while (ans < M) {
			if (tab.count(r)) return ans += tab[r];
			ans += d, r = 1ll * r * block % M;
		}
		return M + 1;
	} // Pay attention that no solution is possible.
	void recover(){
		tab.clear();
	}
}using namespace BSGS;

void work(){
	int n, x; read(n, x);
	init(1ll * (n - 1) * (n - 1) % M);
	int res = min(	query((1ll * n * x + M - (n - 1)) % M) << 1, 
					query(1ll * (1ll * n * x + n - 1) % M * getinv(n - 1) % M) << 1 | 1);
	printf("%d\n", res < M - 1 ? res : -1);
}
void clear(){
	recover();
}
int main(){
	int T; read(T);
	while (T--) work(), clear();
	return 0;
}

