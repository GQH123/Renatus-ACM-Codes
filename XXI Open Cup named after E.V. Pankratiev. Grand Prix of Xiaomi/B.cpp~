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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll unsigned long long int  

int ct = 0;
long long int lis[maxn << 1];
ll sum[2][maxn << 1];
ll num[2][maxn << 1];
ll getsum(bool side, int x) {
	ll ans = 0;
	while (x <= ct) {
		ans += sum[side][x];
		x += lowbit(x);
	}
	return ans;
}
ll getnum(bool side, int x) {
	ll ans = 0;
	while (x) {
		ans += num[side][x];
		x -= lowbit(x);
	}
	return ans;
}
void modsum(bool side, int x, ll v){
	while (x) {
		sum[side][x] += v;
		x -= lowbit(x);
	} 
}
void modnum(bool side, int x, ll v){
	while (x <= ct) {
		num[side][x] += v;
		x += lowbit(x);
	} 
}
struct ele{
	bool side; int x; long long int v, fixv;
	ele(bool side, int x, long long int v, long long int fixv) : side(side), x(x), v(v), fixv(fixv){}
	ele(){}
	bool operator < (const ele b) const{
		return v < b.v;
	}
}p[maxn << 1];
int cp = 0;

int n; int a[maxn];
long long int pre[maxn], suf[maxn];
ll ans = 0;

int sidenum[2];
void solve(int l, int r) {
	if (l == r) {
		ans += a[l];
		return;
	}
	else {
		int mid = ((r - l) >> 1) + l;
		solve(l, mid), solve(mid + 1, r);
		
		long long int mi = suf[mid + 1], mxd = suf[mid] - mi, mxf = suf[mid] - mi;
		per(i, mid, l) {
			mxd = max(mxd, suf[i] - mi);
			mxf = max(mxf, suf[i] - suf[mid + 1]);
			p[++cp] = ele(0, i, mxd, mxf);
			mi = min(mi, suf[i]);
		}
		
		mi = pre[mid], mxd = pre[mid + 1] - mi, mxf = pre[mid + 1] - mi;
		rep(i, mid + 1, r) {
			mxd = max(mxd, pre[i] - mi);
			mxf = max(mxf, pre[i] - pre[mid]);
			p[++cp] = ele(1, i, mxd, mxf);
			mi = min(mi, pre[i]);
		}
		
		sort(p + 1, p + 1 + cp);
		rep(i, 1, cp) {
			lis[++ct] = p[i].fixv, lis[++ct] = p[i].v - p[i].fixv;
		}
		sort(lis + 1, lis + 1 + ct);
		ct = unique(lis + 1, lis + 1 + ct) - lis - 1;
		rep(i, 1, cp) {
			int pos = lower_bound(lis + 1, lis + 1 + ct, p[i].v - p[i].fixv) - lis;
			ll num = getnum(p[i].side ^ 1, pos - 1);
			ll sum = getsum(p[i].side ^ 1, pos);
			//ll vs = getsumv(p[i].side ^ 1, pos);
			ans += 1ull * (sidenum[p[i].side ^ 1] - num) * p[i].fixv + sum + 1ull * num * p[i].v;
			
			pos = lower_bound(lis + 1, lis + 1 + ct, p[i].fixv) - lis;
			modnum(p[i].side, pos, 1);
			modsum(p[i].side, pos, p[i].fixv);
			sidenum[p[i].side]++;
		}
		
		rep(i, 0, ct) sum[0][i] = sum[1][i] = num[0][i] = num[1][i] = 0;
		ct = cp = sidenum[0] = sidenum[1] = 0;
	}
}



int main(){
	read(n); rep(i, 1, n) read(a[i]);
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	per(i, n, 1) suf[i] = suf[i + 1] + a[i];
	solve(1, n);
	printf("%llu\n", ans);
	return 0;
}

