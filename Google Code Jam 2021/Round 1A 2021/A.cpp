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

#define maxn 220
#define maxs 2020  
#define maxb
#define inf 
#define eps
#define M 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 

int len[maxn];
char s[maxn][maxs];
int dep(char* s, int x) {
	int l = 0;
	while (x) {	
		s[l++] = x % 10 + '0', x /= 10;
	}
	reverse(s, s + l);
	s[l] = '\0';
	return l;
}
int add(char* s, int l) {
	bool carry = 1;
	per(i, l - 1, 0) {
		if (!carry) break;
		if (s[i] == '9') carry = 1, s[i] = '0';
		else s[i] += 1, carry = 0;
	}
	if (carry) {
		s[l + 1] = '\0';
		per(i, l, 1) s[i] = s[i - 1];
		s[0] = '1';
		l += 1;
	}
	return l;
}

int n, a[maxn];
int main(){
    int T; read(T);
    rep(TT, 1, T){
    	printf("Case #%d: ", TT);
        read(n); rep(i, 1, n) read(a[i]), len[i] = 0;
        rep(i, 1, n) len[i] = dep(s[i], a[i]);
        int ans = 0;
        
        len[1] = add(s[1], len[1]);
        rep(i, 2, n) {
        	if (len[i] > len[i - 1]) {
        		len[i] = add(s[i], len[i]);
        		//printf("\n%s", s[i]);
        		continue; 
        	}
        	int f = -1;
        	srep(j, 0, len[i]) {
        		if (s[i][j] != s[i - 1][j]) {
        			f = s[i - 1][j] < s[i][j];
        			break;
        		}
        	}
        	if (f == 1) {
        		srep(j, len[i], len[i - 1]) s[i][j] = '0';
        		ans += len[i - 1] - len[i];
        		len[i] = len[i - 1];
        	}
        	else if (f == 0){
        		rep(j, len[i], len[i - 1]) s[i][j] = '0';
        		ans += len[i - 1] - len[i] + 1;
        		len[i] = len[i - 1] + 1;
        	}
        	else {
        		srep(j, len[i], len[i - 1]) s[i][j] = s[i - 1][j]; 
        		ans += len[i - 1] - len[i];
        		len[i] = len[i - 1];
        	}
        	
        	len[i] = add(s[i], len[i]);
        	
        	//printf("\n%s", s[i]);
        }
        rep(i, 1, n) srep(j, 0, len[i]) s[i][j] = '\0';
        printf("%d\n", ans);
    }
	return 0;
}

