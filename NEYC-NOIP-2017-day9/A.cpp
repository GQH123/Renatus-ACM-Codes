#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define pb push_back
#define pc putchar
#define maxn
#define maxm
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)

/*********************

#define Author Renatus

*********************/

using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}	

int _num[30];
template<class T> void write(T x, char sep = '\n'){
	if (!x) { pc('0'), pc(sep); return; }
	if (x < 0) pc('-'), x = -x;
	int cn = 0;
	while (x) _num[++cn] = x % 10, x /= 10;
	while (cn) pc('0' + _num[cn--]); pc(sep);
}

int pri[maxn], cp = 0;
bool vis[maxn];
void init(int mx){
	rep(i, 2, mx){
		if (!vis[i]) pri[++cp] = i;
		rep(j, 1, cp) {
			if (i * pri[j] > mx) break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}

int main(){
	
		freopen(".in", "r", stdin);
		
	init();
	
	return 0;
}
