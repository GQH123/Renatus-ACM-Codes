#include <bits/stdc++.h>
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k, a[maxn];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> s;
//multiset<int> :: iterator it;

int play(int k) {
	s.clear();
	rep(i, 1, k) s.insert(pii(a[i], i)); 
	int res = max(res, s.find_by_order(((k + 1) >> 1) - 1) -> fi);
	rep(i, k + 1, n) { 
		s.erase(pii(a[i - k], i - k));
		s.insert(pii(a[i], i));
		res = max(res, s.find_by_order(((k + 1) >> 1) - 1) -> fi);
	}
	return res;
}
int main(){
	read(n, k);
	rep(i, 1, n) read(a[i]);
	
	//cerr << s.find_by_order(0) -> fi << endl;
	int res = 0;
	res = max(res, play(k));
	if (k < n) res = max(res, play(k + 1));
	write(res);
	/*
	int res = 0;
	it = s.begin();
	srep(i, 1, (k + 1) >> 1) it++;
	res = max(res, *it);
	rep(i, k + 1, n) {
		int x = a[i - k];
		if (k & 1) {
			if (x < 
		}
		else {
			
		}
	}
	*/
	return 0;
}

