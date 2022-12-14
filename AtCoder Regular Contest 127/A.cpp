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
#define eps
#define M 
#define ll long long int 

int num[20], cp = 0;
void dep(ll n) {
	while (n) num[cp++] = n % 10, n /= 10; 
}

ll ten[20];

int main(){
	ten[0] = 1; rep(i, 1, 19) ten[i] = ten[i - 1] * 10;

	ll n; read(n);
	dep(n);
	
	ll ans = 0, res = 0; int op = 1;
	rep(l, 1, cp) {
		ans = 0;
		if (op == 1) {
			if (num[cp - l] > 1) op = 0;
			else if (num[cp - l] == 1) op = 1;
			else op = 2;
		}
		
		if (op == 0) {
			int bla = cp - l;
			if (bla < 0) break;
			if (bla == 0) ans++;
			else ans += 9ll * ten[bla - 1];
		}
		else if (op == 1) {
			if (cp != l) {
				rep(dig, 0, num[cp - l - 1]) {	
					if (dig == 1) continue;
					if (dig == num[cp - l - 1]) {
						ans += n % ten[cp - l - 1] + 1;
					}
					else {
						ans += ten[cp - l - 1];
					}
				}
			}
			else ans++;
		}
		
		per(pos, cp - 2, 0) {
			int bla = pos + 1 - l;
			if (bla < 0) break;
			if (bla == 0) ans++;
			else ans += 9ll * ten[bla - 1];
		}
		
		res += l * ans;
	}
	
	printf("%lld\n", res);
	
	return 0;
}

