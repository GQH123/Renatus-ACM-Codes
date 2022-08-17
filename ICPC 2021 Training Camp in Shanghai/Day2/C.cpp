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

#define maxn 100020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define ll long long int 

int power(int x, int y) {
	int ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) {
	return power(x, M - 2);
}

int mi[maxn], imi[maxn];

vector<int> d[maxn];
int dnum[maxn];
void init(){
	mi[0] = 1;
	srep(i, 1, maxn) mi[i] = mi[i - 1] * 26ll % M;
	int inv26 = getinv(26);
	//cerr << inv26 << endl;
	imi[0] = 1;
	srep(i, 1, maxn) imi[i] = 1ll * imi[i - 1] * inv26 % M;
	
	srep(i, 1, maxn) {
		for (int j = i; j < maxn; j += i) d[j].pb(i); 
		dnum[i] = d[i].size();
	}
}

int p[maxn], mu[maxn], cp = 0;
bool vis[maxn];
void calmu(){
	mu[1] = 1;
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i, mu[i] = M - 1;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = M - mu[i];
		}
	}
}

vector<int> f[maxn], g[maxn];

void cal(){
	/*
	srep(i, 1, maxn) {
		for (auto it: d[i]) {
			printf("%d ", it);
		}
		printf("\n");
	}
	*/


	srep(i, 1, maxn) {
		srep(j, 0, dnum[i]) {
			g[i].pb(1ll * mi[d[i][j]] * imi[i] % M);
		}
	}
	srep(i, 1, maxn) {
		srep(j, 0, dnum[i]){
			int dd = d[i][j], res = 0, ptr = 0;
			
			srep(k, 0, dnum[dd]) {
				int ddd = d[dd][k];
				while (d[i][ptr] != ddd) ptr++;
				
				res += 1ll * g[i][ptr] * mu[dd / ddd] % M;
				mo(res);
			}
			//printf("%d ", res);
			res = 1ll * res * getinv(dd) % M;
			f[i].pb(res); 
		}
		//printf("\n");
	}
	srep(i, 1, maxn) {
		per(j, dnum[i] - 2, 0){
			f[i][j] += f[i][j + 1]; 
			mo(f[i][j]);
			//printf("%d ", f[i][j]);
		}
		//printf("\n");
	}
}
int lis[maxn], cs = 0;
int get(int x, int y) {
	if (x > y) swap(x, y);
	cs = 0;
	srep(i, 0, dnum[x]) lis[++cs] = d[x][i];
	srep(i, 0, dnum[y]) lis[++cs] = d[y][i];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	
	int pa = 0, pb = 0, res = 0, last = 0;
	
	//int rres = 0;
	rep(i, 1, cs) {
		res += 1ll * (lis[i] - last) * f[x][pa] % M * f[y][pb] % M;
		
		//rres += 1ll * (lis[i] - last) * f[x][pa] % M;
		//mo(rres);
		
		
		mo(res);
		if (lis[i] == d[x][pa]) pa++;
		if (lis[i] == d[y][pb]) pb++;
		if (pa == dnum[x] || pb == dnum[y]) break; 
		last = lis[i];
	}
	//cerr << rres << endl;
	//assert(rres == 1);
	return res;
}

int n, a[maxn];
int main(){
	init();
	calmu();
	cal();
	
	read(n); rep(i, 1, n) read(a[i]);
	if (n == 1) {
		puts("1");
		return 0;
	}
	int res = get(a[1], a[n]);
	srep(i, 1, n) {
		res += get(a[i], a[i + 1]), mo(res);
	}
	printf("%d\n", res);
	
	return 0;
}

