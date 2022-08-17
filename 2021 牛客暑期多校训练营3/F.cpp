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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps 1e-7
#define M 
#define ll long long int 

int dcmp(double x, double y) {
	if (x - y > eps) return 1;
	if (y - x > eps) return -1;
	return 0;
}

bool fuck = false;
bool frac = false;
double cal(double a, int X, double b) {
	switch(X){
		case 1: return a + b;
		case 2: return a - b;
		case 3: return a * b;
		case 4: {
			if (dcmp(b, 0) == 0) { fuck = true; return -1; }
			double res = a / b;
			if (dcmp(round(res), res) != 0) frac = true;
			return res;
		} 
		case 5: return b - a;
		case 6: {
			if (dcmp(a, 0) == 0) { fuck = true; return -1; }
			double res = b / a;
			if (dcmp(round(res), res) != 0) frac = true;
			return res;
		} 
	}
}

int n, m;

struct ele{
	int res[4];
};
vector<ele> ress;

void print(){
	printf("%d\n", (int)ress.size());
	for (auto it: ress) {
		srep(i, 0, n) {
			printf("%d ", it.res[i]);
		}
		printf("\n");
	}
}

int lis[5];
int main(){
	read(n, m);
	if (n == 1) {
		puts("0");
		return 0;
	}
	if (n == 2) {
		rep(a, 1, 13) rep(b, a, 13) {
			bool ok = false;
			lis[1] = a, lis[2] = b;
			do{
				rep(X1, 1, 6) {
					frac = false;
					double res = cal(lis[1], X1, lis[2]);
					if (dcmp(res, m) == 0) {
						ok = true;
						if (!frac) goto fail2;
					}
				}
			}while (next_permutation(lis + 1, lis + 5));
			if (ok) {
				ele op;
				op.res[0] = a, op.res[1] = b;
				ress.pb(op);
			}
			fail2:; 
		}
		print();
		return 0;
	}
	if (n == 3) {
		rep(a, 1, 13) rep(b, a, 13) rep(c, b, 13){
			bool ok = false; double res = -1;
			lis[1] = a, lis[2] = b, lis[3] = c;
			do{
				rep(X1, 1, 6) rep(X2, 1, 6){
					frac = false;
					res = cal(cal(lis[1], X1, lis[2]), X2, lis[3]);
					if (fuck) { fuck = false; continue; }
					if (dcmp(res, m) == 0) {
						ok = true;
						if (!frac) goto fail3;
					}
				}
			}while (next_permutation(lis + 1, lis + 5)); //XXX
			if (ok) {
				ele op;
				op.res[0] = a, op.res[1] = b, op.res[2] = c;
				ress.pb(op);
			}
			fail3:; 
		}
		print();
		return 0;
	}
	if (n == 4) {
		rep(a, 1, 13) rep(b, a, 13) rep(c, b, 13) rep(d, c, 13){
			bool ok = false; double res = -1; 
			if (a == 1 && b == 1 && c == 11 && d == 12) {
				int rr = 1;
			}
			lis[1] = a, lis[2] = b, lis[3] = c, lis[4] = d;
			do{
				rep(X1, 1, 6) rep(X2, 1, 6) rep(X3, 1, 6){
					
					frac = false;
					res = cal(cal(cal(lis[1], X1, lis[2]), X2, lis[3]), X3, lis[4]);
					if (fuck) { fuck = false; continue; }
					if (dcmp(res, m) == 0) {
						ok = true;
						if (!frac) goto fail4;
					}
				}
			}while (next_permutation(lis + 1, lis + 5)); 
			lis[1] = a, lis[2] = b, lis[3] = c, lis[4] = d;
			do{ 
				rep(X1, 1, 6) rep(X2, 1, 6) rep(X3, 1, 6){
					frac = false;
					res = cal(cal(lis[1], X1, lis[2]), X2, cal(lis[3], X3, lis[4]));
					if (fuck) { fuck = false; continue; }
					if (dcmp(res, m) == 0) {
						ok = true;
						if (!frac) goto fail4;
					}
				}
			}while (next_permutation(lis + 1, lis + 5));  
			if (ok) {
				ele op;
				op.res[0] = a, op.res[1] = b, op.res[2] = c, op.res[3] = d;
				ress.pb(op);
			}
			fail4:; 
		}
		print();
		return 0;
	}
	return 0;
}

