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
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 100020
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

int pvis[maxn], p[maxn], cp = 0;
void init(){
	srep(i, 2, maxn) {
		if (!pvis[i]) p[++cp] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			pvis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
bool vis[maxn];
int num = n;
int main(){
	init(); //cout << cp << endl;
	//rep(i, 1, 10) cout << p[i] << ' '; cout << endl;
	cin >> n;
	int siz = 60;
	rep(i, 1, cp) {
		cout << "A " << p[i] << endl; 
		for (register int j = p[i]; j <= n; j += p[i]) {
			if (!vis[j]) vis[j] = 1, num--;
		}
		if (i % 60 == 0) {
			cout << "B " << 1 << endl;
			cin >> res;
			if (res != num) {
				num = res;
				rep(j, i - 59, i) {
					
				}
			}
		}
	}
	return 0;
}

