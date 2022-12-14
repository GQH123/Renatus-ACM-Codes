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

#define maxn 200021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, lis[maxn];
int c[maxn];

void add(int x, int v){ 
	while (x) {
		c[x] += v;
		x -= lowbit(x);
	}
}
int get(int x) {
	int ans = 0;
	while (x <= n) {
		ans += c[x];
		x += lowbit(x); 
	}
	return ans;
}

ll getnum() {
	rep(i, 0, n) c[i] = 0;
	ll ans = 0;
	rep(i, 1, n) {
		ans += get(lis[i]);
		add(lis[i], 1);
	}
	return ans;
}


int all_mx = 0;

bool vis[maxn];
int dfs(int x) {
	if (vis[x]) return 0;
	vis[x] = 1;
	return dfs(lis[x]) + 1;
}
void getloop(bool second = false){
	rep(i, 1, n) vis[i] = 0;
	int num = 0, mx = 0;
	rep(i, 1, n) {
		if (!vis[i]) {
			int l = dfs(i);
			num++, mx = max(mx, l);
		}
	}
	//cerr << num << ' ' << mx << endl;
	
	if (second) all_mx = max(all_mx, num);
}

int main(){
	ll mx = -1ll * maxn * maxn, mi = 1ll * maxn * maxn;
	srand(time(NULL) + rand());
	while (1) { 
		n = rand() % 50001 + 50000;
		rep(i, 1, n) lis[i] = i;
		rep(i, 1, 7 * n) {
			int x = rand() % n + 1, y = rand() % n + 1;
			while (x == y) x = rand() % n + 1, y = rand() % n + 1;
			swap(lis[x], lis[y]); 
		}
		//cerr << getnum() << endl;
		ll res = getnum();
		
		getloop(true);
		
		
		rep(i, 1, n) {
			int x = rand() % n + 1, y = rand() % n + 1;
			while (x == y) x = rand() % n + 1, y = rand() % n + 1;
			swap(lis[x], lis[y]); 
		}
		ll _res = getnum();
		
		//cerr << getnum() << endl;
		
		//cerr << _res - res << ' ';
		
		mi = min(mi, _res - res);
		
		
		
		rep(i, 1, n) lis[i] = i;
		rep(i, 1, 3 * n) {
			int x = rand() % n + 1, y = rand() % n + 1;
			while (x == y) x = rand() % n + 1, y = rand() % n + 1;
			swap(lis[x], lis[y]); 
		}
		//cerr << getnum() << endl;
		res = getnum();
		
		getloop(false);
		
		
		rep(i, 1, n) {
			int x = rand() % n + 1, y = rand() % n + 1;
			while (x == y) x = rand() % n + 1, y = rand() % n + 1;
			swap(lis[x], lis[y]); 
		}
		_res = getnum();
		
		//cerr << getnum() << endl;
		
		//cerr << _res - res << endl;
		
		mx = max(mx, _res - res);
		
		//cerr << mi << ' ' << mx << endl;
		
		cerr << all_mx << endl;
		
		
	}
	return 0;
}

