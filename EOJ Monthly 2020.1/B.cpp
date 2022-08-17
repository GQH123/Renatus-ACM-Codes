#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
int ct = 1;

pii ans[maxn];
int cs = 0;
/*
inline void Add_Link(int x, int l){
	int last = x;
	rep(i, 1, l){
		ans[++cs] = pii(last, ++ct);
		last = ct;
	}
}
void solve(int x, int s){
	ans[++cs] = pii(x, ++ct);
	x = ct;
	Add_Link(x, s / 3), Add_Link(x, s / 3);
	solve(x, s / 3);
}
*/
inline void Add_Link(int x, int l){
	int last = x;
	rep(i, 1, l){
		ans[++cs] = pii(last, ++ct);
		last = ct;
	}
}
int res = 0;
void solve(int x, int s){
	if (s % 3 == 1){
		if (s == 1) {res = ct; return;}
		Add_Link(x, s / 3);
		int mid = ct;
		Add_Link(mid, s / 3);
		Add_Link(mid, 1);
		solve(ct, s / 3);
		
	}
	else if (s % 3 == 2){
		Add_Link(x, s / 3 + 1);
		if (s == 2) {res = ct; return;}
		int mid = ct;
		Add_Link(mid, s / 3);
		Add_Link(mid, 1);
		solve(ct, s / 3);
		
	}
	else {
		Add_Link(x, s / 3);
		int mid = ct;
		Add_Link(mid, s / 3 - 1);
		Add_Link(mid, 1);
		if (s == 3) {res = ct; return;}
		solve(ct, s / 3);
		
	}
	//if (s == 4) res = ct;
}
int main(){
	n = 65535;
	solve(1, n);
	/*
	Add_Link(1, n / 3);
	int nex = ct;
	Add_Link(ct, n / 3);
	solve(nex, n / 3);
	*/
	printf("%d %d\n", n, res);
	rep(i, 1, cs) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}
