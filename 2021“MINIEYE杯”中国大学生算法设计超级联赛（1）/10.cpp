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

#define maxn 200021
#define maxm 200021
#define maxs 200021
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

namespace Mo{ 
	namespace DS{
		int n, idx[maxn], end[maxs], num[maxn], val[maxs], bs;
		void init(int n){
			DS :: n = n;
			bs = (int)sqrt(n) + 5;
			rep(i, 1, n) idx[i] = (i - 1) / bs + 1;
			rep(i, 1, idx[n]) end[i] = bs * i;
		}
		void update(int x, int v) {
			if (num[x] && !(num[x] + v)) 	val[idx[x]]--;
			else if (!num[x] && num[x] + v)	val[idx[x]]++;
			num[x] += v;
		}
		int get(int l, int r) {
			int bl = idx[l], br = idx[r], ans = 0;
			if (bl == br) {
				rep(i, l, r) ans += num[i] > 0;
				return ans;
			}
			srep(i, bl + 1, br) 		ans += val[i]; 
			rep(i, l, end[bl]) 			ans += num[i] > 0;
			rep(i, end[br - 1] + 1, r) 	ans += num[i] > 0;
			return ans;
		} 
		void recover(){
			rep(i, 1, idx[n]) val[i] = 0;
			rep(i, 1, n) num[i] = 0;
		}
	}
	int n, m, bs, a[maxn], idx[maxn], res[maxm]; bool vis[maxn];
	struct query{
		int l, r, yl, yr, id;
		query(int l, int r, int yl, int yr, int id) : l(l), r(r), yl(yl), yr(yr), id(id){}
		query(){}
		bool operator < (const query b) const{
			return idx[l] == idx[b.l] ? r < b.r : idx[l] < idx[b.l];
		}
	}q[maxm];
	void update(int x) {
		DS :: update(a[x] + 1, vis[x] ? -1 : 1);
		vis[x] ^= 1;
	}  
	void work(int n, int m){
		Mo :: n = n, Mo :: m = m;
		DS :: init(100020);
		bs = (int)sqrt(n) + 5;
		rep(i, 1, n) idx[i] = (i - 1) / bs + 1; 
		sort(q + 1, q + 1 + m);
		int l = 1, r = 0;
		rep(i, 1, m) {
			while (r < q[i].r) update(++r);
			while (l > q[i].l) update(--l);
			while (r > q[i].r) update(r--);
			while (l < q[i].l) update(l++);
			res[q[i].id] = DS :: get(q[i].yl + 1, q[i].yr + 1);
		}
		rep(i, 1, m) printf("%d\n", res[i]);
	}
	void recover(){
		DS :: recover();
		rep(i, 1, n) vis[i] = 0;
	} 
}using namespace Mo;
void work(){
	int n, m; read(n, m);
	rep(i, 1, n) read(a[i]);
	int x, y, z, w;
	rep(i, 1, m) read(x, y, z, w), q[i] = query(x, z, y, w, i);
	work(n, m);
}
void clear(){
	recover();
}

int main(){
	int T; read(T);
	while (T--) work(), clear();
	return 0;
}

