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

#define maxn 2000022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int l, r;
vector<int> d[maxn];

int ufs[maxn];
int find_root(int x) {
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
int ct = 0;
ll ans = 0;
void merge(int x, int y) {
	ll d = 1ll * x * y / __gcd(x, y);
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	ans += d;
	ufs[x] = y;
	ct++;
}


struct ele{
	ll v, id, p;
	ele(ll v, ll id, ll p) : v(v), id(id), p(p){}
	ele(){}
	bool operator < (const ele b) const{
		return v == b.v ? id == b.id ? p > b.p : id > b.id : v > b.v;
	}
};

priority_queue<ele> pq;

int main(){
	read(l, r); int n = r - l + 1;
	rep(i, l, r) ufs[i] = i;
	rep(i, 1, r) {
		int st = i * ((l - 1) / i + 1);
		for (int j = st; j <= r; j += i) d[i].pb(j); 
	}
	per(i, r, 1) {
		int ds = d[i].size();
		if (ds == 0 || ds == 1) continue;
		int st = d[i][0];
		rep (j, 1, 1) {
			//merge(st, d[i][j]); 
			pq.push(ele(1ll * st * d[i][j] / __gcd(st, d[i][j]), i, j));
		}
		//if (ct == n - 1) break;
		//cerr << ans << endl;
	}
	while (ct < n - 1 && !pq.empty()) {	
		ele op = pq.top(); pq.pop();
		merge(d[op.id][0], d[op.id][op.p]);
		op.p++;
		if (op.p < d[op.id].size()) pq.push(ele(1ll * d[op.id][0] * d[op.id][op.p] / __gcd(d[op.id][0], d[op.id][op.p]), op.id, op.p));
	}
	assert(ct == n - 1);
	printf("%lld\n", ans);
	return 0;
}

