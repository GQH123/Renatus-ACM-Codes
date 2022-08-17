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
    #define isletter(ch) ('0' <= ch && ch <= '9')
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

#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n; char l[maxn], r[maxn];
int nxt0[maxn];
int nxt1[maxn];

int DP(int pos, int op1, int op2, int up, int down) {
	if (pos == -1) return 0;
	if (vis[pos][op1][op2][up][down]) return dp[pos][op1][op2][up][down];
	vis[pos][op1][op2][up][down] = 1;
	int& ans = dp[pos][op1][op2][up][down];
	
}
int main(){
	read(n);
	reads(l), reads(r);
	bool have_one = 0;
	int last = n;
	sper(i, n - 1, 0) {
		
		nxt0[i] = last;
		if (l[i] == '0') last = i;
	}
	last = n;
	sper(i, n - 1, 0) {
		
		nxt1[i] = last;
		if (r[i] == '1') last = i;
	}
	srep(i, 0, n) {
		if (l[i] == r[i]) {
			if (l[i] == '1') have_one = 1;
		}
		else {
			if (have_one){ 
				if (nxt0[i] <= nxt1[i]) {// x - 1
					bool lz = 1;
					srep(j, 0, i) {
						if (l[j] == '0') {
							if (!lz) printf("0");
						}
						else printf("1"), lz = 0;
					}
					printf("1"); srep(j, i + 1, nxt0[i]) printf("0");
					srep(j, nxt0[i], n) printf("1");
					return 0;
				} 
				else {//x - 3
					bool lz = 1;
					srep(j, 0, i) {
						if (l[j] == '0') {
							if (!lz) printf("0");
						}
						else printf("1"), lz = 0;
					}
					printf("1"); srep(j, i + 1, nxt1[i]) printf("0");
					srep(j, nxt1[i], n) printf("1");
				}
			}
			else {
				bool lz = 1;
				srep(j, 0, i) {
					if (l[j] == '0') {
						if (!lz) printf("0");
					}
					else printf("1"), lz = 0;
				}
				srep(j, i, n) printf("1");
				return 0;
			}
		}
	}
	return 0;
}

