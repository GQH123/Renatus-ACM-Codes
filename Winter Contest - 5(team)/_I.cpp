#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
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
#define inf  2000000020
#define eps
#define M 
#define ll long long int 

struct pii{
	int first, second, rest;
	pii(int x, int y, int z) : first(x), second(y), rest(z){}
	pii(){}
	bool operator < (const pii b) const{
		return first == b.first ? second < b.second : first < b.first;
	}
};
map<pii, pair<pii, pii>> fa;
set<pii> s;
set<pii> :: iterator it;

pii get(int x) {
	it = s.lower_bound(pii(x, -1, 0));
	if (it -> fi > x) {
		--it;
		if (it -> fi <= x && x <= it -> se) return *it;
		else return pii(-1, -1, -1);
	}
	if (it -> fi <= x && x <= it -> se) return *it;
	else return pii(-1, -1, -1);
}
pii mergeleft(pii x){
	it = s.lower_bound(x);
	if (it != s.begin() && (--it) -> se == x.fi - 1) { 
		pii k = pii(it -> fi, x.se, 0);
		fa[k] = pair<pii, pii>(*it, x);
		s.erase(x), s.erase(it);
		s.insert(k);
		return k;
	}
	else return x;
}
pii mergeright(pii x){
	it = s.upper_bound(x);
	if (it -> fi == x.se + 1) {
		pii k = pii(x.fi, it -> se, 0);
		fa[k] = pair<pii, pii>(x, *it);
		s.erase(x), s.erase(it);
		s.insert(k);
		return k;
	}
	else return x;
}

void del(pii p, int x) {
	pii left = fa[p].fi, right = fa[p].se;
	if (left.fi <= x && x <= left.se) {
		s.insert(right);
		if (left.rest) left.rest--, left.se--, s.insert(left);
		else del(left, x, 1);
	}
	else {
		s.insert(left); 
		if (right.rest) right.rest--, right.fi++, s.insert(right);
		else del(right, x, 0); 
	}
}

#define l first
#define r second
int main(){
	int n; read(n);
	s.insert(pii(inf, inf, inf));
	int op, x;
	rep(i, 1, n) {
		read(op, x);
		pii k = get(x);
		if (k.fi == -1) {
			k = pii(x, x, 0);
			s.insert(k);
			k = mergeleft(k);
			k = mergeright(k); 
		}
		else {
			s.erase(k);
			if (op == 1){ 
				if (k.l == 0) {
					k.r++;
					k.rest++;
					s.insert(k);
					mergeright(k); 
				}
				else {
					k.l--;
					k.rest++;
					s.insert(k);
					mergeleft(k); 
				}
			}
			else {
				if (k.l == 0) {
					if (k.rest) k.r--, k.rest--, s.insert(k);
					else {
						s.insert(fa[k].fi);
						pii right = fa[k].se; right.l++, right.rest--;
						if (right.fi <= right.se) s.insert(right);
					}
				}
				else {
					if (k.rest) k.l++, k.rest--, s.insert(k);
					else {
						s.insert(fa[k].fi);
						pii right = fa[k].se; right.l++, right.rest--;
						if (right.fi <= right.se) s.insert(right);
					}
				}
			}
		}
		
		cerr << "#" << i << ":" << endl;
		for (auto pi : s){
			cerr << pi.l << ' ' << pi.r << ' ' << pi.rest << endl;
		}
		
		k = get(0);
		printf("%d\n", k.se == -1 ? 0 : k.se + 1);
	}
	return 0;
}

