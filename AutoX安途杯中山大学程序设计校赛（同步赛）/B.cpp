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
    #define isletter(ch) ('A' <= ch && ch <= 'Z')
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

#define maxn 300021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
int ctag[maxn], rtag[maxn], dtag, cnum, rnum, dnum;
ll anum;

int get_ans_D(){
	return dtag ? n - dnum : dnum;
}

int get_ans_R(int x){
	int rd = cnum - ctag[x] + (dtag ^ ctag[x]);
	return rtag[x] ? n - rd : rd;
}

int get_ans_C(int x) {
	int rd = rnum - rtag[x] + (dtag ^ rtag[x]);
	return ctag[x] ? n - rd : rd;
}

int main(){
	int T, x;
	read(T);
	while (T--) {
		char op[5];
		read(n, m);
		rep(i, 1, n) rtag[i] = ctag[i] = 0; dtag = cnum = rnum = dnum = anum = 0;
		
		rep(i, 1, m) {
			reads(op);
			if (op[0] == 'D') {
				anum -= get_ans_D();
				dtag ^= 1;
				anum += get_ans_D();
			}
			else if (op[0] == 'R') { 
				read(x);
				anum -= get_ans_R(x);
				rnum -= rtag[x];
				dnum -= (rtag[x] ^ ctag[x]);
				
				rtag[x] ^= 1;
				
				rnum += rtag[x];
				dnum += (rtag[x] ^ ctag[x]);
				anum += get_ans_R(x);
			}
			else {
				read(x);
				anum -= get_ans_C(x);
				cnum -= ctag[x];
				dnum -= (rtag[x] ^ ctag[x]);
				
				ctag[x] ^= 1;
				
				cnum += ctag[x];
				dnum += (rtag[x] ^ ctag[x]);
				anum += get_ans_C(x);
			}
			printf("%lld\n", anum);
		}
	}
	return 0;
}

