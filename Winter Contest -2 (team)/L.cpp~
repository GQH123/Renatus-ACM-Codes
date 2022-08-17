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

#define maxn 1020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps 
#define ll long long int 

int solve(char* s, int n) {
	int i = 0, j = 1, k = 0;
	while (k < n && i < n && j < n) {
		if (s[(i + k) % n] == s[(j + k) % n]) k++;
		else {
			s[(i + k) % n] > s[(j + k) % n] ? i += k + 1 : j += k + 1;
			if (i == j) i++; k = 0;
		}
	} return min(i, j);
}

#define maxM 2
#define bas 2333
int M[] = {19260817, 1000000007, 1000000009};
int has(char* s, int n, int m) {
	int res = 0; srep(i, 0, n) res = (1ll * bas * res + (s[i] - 'a')) % m; 
	return res;
}


set<pair<pii, int>> sta[maxn];
char s[maxn];
int n;
int main(){
	read(n);
	rep(T, 1, n) {
		int l = reads(s);
		int pos = solve(s, l);
		srep(i, 0, l) s[i + l] = s[i];
		sta[l].insert(pair<pii,int>(   pii(has(s + pos, l, M[0]), has(s + pos, l, M[1])), has(s + pos, l, M[2])));
	}
	int sum = 0;
	srep(i, 0, maxn) sum += sta[i].size();
	write(sum);
	return 0;
}

