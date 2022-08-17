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

#define maxn 200021
#define inf 
#define eps
#define M 
#define ll long long int 
#define maxb 31

namespace Trie{	
	#define ls ch[0][o]
	#define rs ch[1][o]
	int ct, root, ch[2][maxn * maxb], val[maxn * maxb], s[maxn * maxb];
	inline int create(){
		val[++ct] = -1;
		s[ct] = 0;
		return ct;
	}
	inline void update(int o, int i){
		s[o]++; val[o] = max(val[o], i);
	}
	void insert(int v, int idx){
		if (!root) root = create();
		int o = root; update(o, idx);
		per(i, maxb - 1, 0) {
			if (!ch[v >> i & 1][o]) ch[v >> i & 1][o] = create();
			o = ch[v >> i & 1][o], update(o, idx);
		}
	}
	int walk(int v, int k, int d, int o, int bound) {
		if (!o) return -1;
		if (!bound || d == -1) return val[o]; 
		if (k >> d & 1) {
			return walk(v, k, d - 1, ch[!(v >> d & 1)][o], 1);
		}
		else {
			return max(	walk(v, k, d - 1, ch[!(v >> d & 1)][o], 0), 
						walk(v, k, d - 1, ch[v >> d & 1][o], 1));
		}
	}
	void recover(){
		rep(o, 1, ct) ls = rs = 0; root = ct = 0; 
	}
}using namespace Trie;

int n, k;
void work(){
	read(n, k);
	int pre = 0, ansn = n + 1, ansl = -1, ansr = -1, x;
	insert(0, 0);
	rep(i, 1, n) {
		read(x);
		pre ^= x;
		int leftend = walk(pre, k, maxb - 1, root, 1);
		if (leftend != -1 && i - leftend < ansn) ansn = i - leftend, ansl = leftend + 1, ansr = i;
		insert(pre, i);
	}
	if (ansn == n + 1) printf("-1\n");
	else printf("%d %d\n", ansl, ansr);
}
void clear(){
	recover();
}

int main(){ 
	int T; read(T);
	while (T--) work(), clear();
	return 0;
}

