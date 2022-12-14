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
#define maxn 100020
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

int n, a[maxn << 1];
int link[maxn << 1], now[maxn];
set<int> s;
bool judge(int x){
	if (x == (n << 1) || a[x] == a[x + 1]) return false;
	int l1 = x, r1 = link[x], l2 = x + 1, r2 = link[x + 1];
	if (l1 > r1) swap(l1, r1); if (l2 > r2) swap(l2, r2);
	if (r1 < l2 || r2 < l1 || (l1 < l2 && r2 < r1) || (l2 < l1 && r1 < r2)) return false;
	return true;
} 

void upd(int x){
	if (x && x < (n << 1) && s.count(x)) s.erase(x); 
	if (x && x < (n << 1) && judge(x)) s.insert(x); 
}

int main(){
	
		//freopen("block.in", "r", stdin);
		//freopen("block.out", "w", stdout);
		
	read(n);
	rep(i, 1, (n << 1)) read(a[i]);
	rep(i, 1, (n << 1)) link[i] = now[a[i]], now[a[i]] = i;
	per(i, (n << 1), 1) {
		if (!link[i]) link[i] = now[a[i]];
		now[a[i]] = i;
	}
	
	srep(i, 1, (n << 1)) if (judge(i)) s.insert(i);
	
	int ans = 0;
	while (!s.empty()){
		int x = *s.begin(); s.erase(s.begin()); ans++; 
		link[link[x]] = x + 1, link[link[x + 1]] = x;
		swap(link[x], link[x + 1]), swap(a[x], a[x + 1]);
		upd(x - 1), upd(x + 1), upd(link[x] - 1), upd(link[x]), upd(link[x + 1] - 1), upd(link[x + 1]);
	}
	rep(i, 1, (n << 1)) write(a[i]);
	write(ans);
	return 0;
}
