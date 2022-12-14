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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

char s[maxn];
int a[maxn], b[maxn], c[maxn], x[maxn], _x[maxn];
int l, _l;
void play_even(int type = 0){
	int d = x[0];
	per(i, l - 1, 0) {
		if (x[i] & 1) x[i]--, x[i - 1] += 10;
		a[i] = b[i] = c[i] = x[i] / 2;
	} 
	while (l > 1 && a[l - 1] == 0) l--; 
	int __l = l;
	if (d & 1) { 
		l = _l;
		int mo = 0;
		rep(i, 0, l - 1) {
			if (i & 1) mo += 11 - _x[i];
			else mo += _x[i];
		}
		mo %= 11;
		if (_x[_l - 1] == 1 && mo != 10) {
			int xx = 0;
			per(i, l - 1, 0) {
				xx = xx * 10 + _x[i];
				a[i] = xx / 11;
				b[i] = _x[i];
				xx %= 11;
			}
			srep(i, 0, l) {
				b[i] -= a[i]; 
				if (b[i] < 0) b[i] += 10, b[i + 1]--;
			}
			while (l > 1 && b[l - 1] == 0) l--;
			bool fir_zero = 1;
			per(i, l - 1, 0) {
				if (a[i] == 0) {
					if (!fir_zero) printf("0");
				}
				else fir_zero = 0, printf("%d", a[i]);
			}if (fir_zero) printf("0"); printf("\n");
			per(i, l - 1, 0) printf("%d", b[i]); printf("\n");
			bool work = 0;
			fir_zero = 1;
			per(i, l - 1, 0) {
				if (a[i] == 0) {
					if (!fir_zero) printf("0"), work = 1;
				}
				else fir_zero = 0, printf("%d", a[i]), work = 1;
			}
			if (!work) printf("-");
			printf("\n");
			return;
		}
		l = __l;
		if (a[0] == 9) {
			int pos = 0;
			while (pos < l && a[pos] == 9) pos++;
			if (pos == l) {
				a[l] = 1;
				per(i, l - 1, 0) a[i] = 0;
				int d = 1;
				per(i, l - 1, 0) {
					if (d) a[i] = 8, b[i] = 1;
					else a[i] = 1, b[i] = 8;
					d ^= 1;
				}
				per(i, l, 0) printf("%d", a[i]); printf("\n");
				per(i, l - 1, 0) printf("%d", b[i]); printf("\n");
				per(i, l - 1, 0) printf("%d", b[i]);
				if (l < 1) printf("-");
				printf("\n");
			}
			else {
				a[pos]++;
				int idx = a[pos];
				int d = 1;
				per(i, pos - 1, 0) {
					if (d) a[i] = idx - 1, b[i] = 9 - a[i];
					else a[i] = 9 - idx + 1, b[i] = idx - 1;
					d ^= 1;
				}
				per(i, l - 1, 0) printf("%d", a[i]); printf("\n");
				per(i, l - 1, 0) printf("%d", b[i]); printf("\n");
				per(i, l - 1, 1) printf("%d", b[i]);
				if (l < 2) printf("-");
				printf("\n");
				
			}
		}
		else {
			a[0]++;  
			per(i, l - 1, 0) printf("%d", a[i]); printf("\n");
			per(i, l - 1, 0) printf("%d", b[i]); printf("\n");
			per(i, l - 1, 1) printf("%d", c[i]); 
			if (l < 2) printf("-");
			printf("\n");
		}
	}
	else { 
		per(i, l - 1, 0) printf("%d", a[i]); printf("\n");
		per(i, l - 1, 0) printf("%d", b[i]); printf("\n");
		per(i, l - 1, 0) printf("%d", c[i]); printf("\n");
	}
}
int main(){
	int T; 
	read(T);
	while (T--){
		_l = l = reads(s);
		reverse(s, s + l);
		srep(i, 0, l) _x[i] = x[i] = s[i] - '0';
		/*
		if (1 & x[0]) {
			int pos9 = 0;
			while (pos9 < l && x[pos9] == 9) pos9++;
			if (!pos9) {
				
			}
			else {
				x[0]--;
				play_even();
			}
		}
		else { 
			play_even();
		}
		*/
		play_even(); 
	}
	return 0;
}

