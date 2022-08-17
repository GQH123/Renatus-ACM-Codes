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
#define plc pair<ll, char> 

char left(char x) {
	if (x == 'A') return 'B';
	if (x == 'B') return 'C';
	if (x == 'C') return 'A';
}
char right(char x) {
	if (x == 'B') return 'A';
	if (x == 'C') return 'B';
	if (x == 'A') return 'C';
}

namespace J1{
	bool judge(ll mid, ll x, ll z) {
		if (mid & 1) {
			x -= 3 * (mid / 2);
			ll y = x;
			y = x - 2;
			x = x - 1;
			
			if (y >= z + 2) return true;
			else return false;
		}
		else {
			x -= 3 * (mid / 2);
			
			if (x >= z + 2) return true;
			else return false;
		}
	}
	ll solve(ll l, ll r, ll x, ll z) {
		while (l < r) {
			ll mid = ((r - l) >> 1) + l;
			if (judge(mid, x, z)) l = mid + 1;
			else r = mid;
		}
		return l;
	}
}

namespace J2{
	bool judge(ll mid, ll x, ll z) {
		if (mid & 1) {
			x -= 2 * mid;
			z -= mid / 2;
			ll y = z;
			z--;
			
			if (x >= z + 3) return true;
			else return false;
		}
		else {
			x -= 2 * mid;
			z -= mid / 2;
			
			if (x >= z + 2) return true;
			else return false;
		}
	}
	ll solve(ll l, ll r, ll x, ll z) {
		while (l < r) {
			ll mid = ((r - l) >> 1) + l;
			if (judge(mid, x, z)) l = mid + 1;
			else r = mid;
		}
		return l;
	}
}

plc ele[10];

int main(){	
	ll x, y, z;
	cin >> x >> y >> z;
	ele[1] = plc(x, 'A'), ele[2] = plc(y, 'B'), ele[3] = plc(z, 'C');
	sort(ele + 1, ele + 1 + 3);
	
	ll thres = 2ll * (ele[1].fi + ele[2].fi) - 1;
	if (ele[3].fi > thres) {
		printf("%c %lld\n", ele[3].se, ele[3].fi - thres);
		return 0;
	}
	if (ele[3].fi == thres) {
		puts("Rubble!"); 
		return 0;
	}
	
	ll stepAB = ele[3].fi - ele[2].fi; 
	ll stepBC = ele[2].fi - ele[1].fi;
	
	if (stepAB < stepBC) {
		ele[3].fi -= 2ll * stepAB;
		ele[2].fi -= stepAB;
		// A = B > C
		ll stepNxt = J1 :: solve(0, 1000000000000000000 + 1, ele[3].fi, ele[1].fi);
		
		ele[3].fi -= 3 * (stepNxt / 2);
		ele[2].fi -= 3 * (stepNxt / 2);
		if (stepNxt & 1) {
			if (left(ele[1].se) == ele[2].se) {
				ele[2].fi -= 2;
				ele[3].fi -= 1;
			}
			else {
				ele[2].fi -= 1;
				ele[3].fi -= 2;
			}
		}
		sort(ele + 1, ele + 1 + 3);
		// Normal Mode
		
		
		assert(ele[3].fi <= ele[1].fi + 2);
	}
	else {
		ele[3].fi -= 2ll * stepBC;
		ele[2].fi -= stepBC;
		//A > B = C
		ll stepNxt = J2 :: solve(0, 1000000000000000000 + 1, ele[3].fi, ele[1].fi);
		
		ele[3].fi -= 2 * stepNxt;
		ele[2].fi -= (stepNxt / 2);
		ele[1].fi -= (stepNxt / 2);
		if (stepNxt & 1) {
			if (left(ele[3].se) == ele[1].se) {
				ele[1].fi--;
			}
			else {
				ele[2].fi--;
			}
		}
		sort(ele + 1, ele + 1 + 3);
		// Normal Mode
		
		assert(ele[3].fi <= ele[1].fi + 2);
	}
	
	if (ele[1].fi == ele[2].fi && ele[2].fi < ele[3].fi) {
		ll stepFinal = ele[1].fi % 3;
		while (stepFinal--) ele[3].se = right(ele[3].se);
		printf("%c %lld\n", ele[3].se, 1ll);
	}
	else puts("Rubble!");  
	
	return 0;
}

