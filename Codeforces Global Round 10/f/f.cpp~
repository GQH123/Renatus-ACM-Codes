#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
ll a[maxn], pre[maxn];
pil q[maxn << 2];
int cq = 0;
int he = 0;
int main(){
	read(n); rep(i, 1, n) read(a[i]), pre[i] = pre[i - 1] + a[i];
	q[++cq] = pil(1, a[1]);
	rep(i, 2, n){
		if (a[i] == q[cq].se) {
			q[cq].fi++;
		} 
		else if (a[i] == q[cq].se + 1){
			q[++cq] = pil(i, a[i]);
		}
		else {
			ll rest = a[i] - q[cq].se;
			while (rest && cq - he >= 2){	
				if (q[cq].fi != i - 1) q[cq + 1] = pil(i, q[cq].se + 1), cq++;
				else {
					
				}
				rest--, a[i]--;
			}
			if (rest){
				/*
				cq = he = 0;
				ll sum = pre[i];
				if (sum % i == 0) {	
					q[++cq] = pil(i, sum / i);
				}
				else {
					ll small = pre[i] / i;
					ll bignum = pre[i] - i * small;
					q[++cq] = pil(i - bignum, small);
					q[++cq] = pil(i, small + 1);
				}  
				*/ 
				ll num = rest / i; 
				q[cq].se += num, rest -= i * num, a[i] -= (i - 1) * num;
				while (rest > 0){
					if (cq == he + 1) q[++cq] = pil(i - 1, q[he + 1].se + 1), rest--;
					q[he + 1].fi--;  
					if (!q[he + 1].fi) he++; 
					rest--, a[i]--;
				}
				if (a[i] == q[cq].se) q[cq].fi++;
				else q[++cq] = pil(i, a[i]);
			}
			else {
				//assert(a[i] == a[i - 1]);
				q[++cq] = pil(i, a[i]);
			}
			a[i] = q[cq].se;
		}
	}
	int ptr = 1;
	rep(i, he + 1, cq){
		pil op = q[i];
		while (ptr <= op.fi) {
			printf("%lld ", op.se);
			ptr++;
		}
	}
	//rep(i, 1, n) printf("%lld ", a[i]);
	return 0;
}

