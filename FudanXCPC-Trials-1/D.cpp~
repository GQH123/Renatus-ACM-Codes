#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 300020
#define maxm
using namespace std;
int n; 
/*
int n; 
pii lis[maxn];
int in[maxn];
int num[maxn];
set<int> s;
void process(){
	rep(i, 1, n) if (!num[i]) s.insert(i);
	rep(i, 1, n - 2){
		int x = in[i];
		printf("%d %d\n", *s.begin(), x);
		s.erase(s.begin());
		num[x]--;
		if (!num[x]) s.insert(x);
	}
	int x = *s.begin();
	s.erase(s.begin());
	int y = *s.begin();
	printf("%d %d\n", x, y);
}
*/

int deg[maxn];
set<pii> s;
pii q[maxn << 2];
int cq = 0, ta = 0;

int main(){
	int x;
	scanf("%d", &n);
	//rep(i, 1, n) scanf("%d", &x), lis[i] = pii(x, i);
	//rep(i, 1, n) scanf("%d", &x); lis[i] = pii(x, i);
	rep(i, 1, n) {
		scanf("%d", deg + i);//, s.insert(pii(deg[i], i));
		if (deg[i] == 1) q[++cq] = pii(deg[i], i);
		else s.insert(pii(deg[i], i));
	}
	while (ta != cq){
		if (s.empty()){
			printf("%d ", q[++ta].se);
			printf("%d\n", q[++ta].se); 
		}
		else {
			pii op = q[++ta];
			pii op2 = *s.begin(); s.erase(op2);
			printf("%d %d\n", op.se, op2.se);
			op2.fi--;
			if (op2.fi > 1) s.insert(op2);
			else q[++cq] = op2;
		}
	}
	/*
	while (!s.empty()) {
		if (s.size() == 2){
			pii op = *s.begin(); s.erase(op);
			pii op2 = *s.begin(); s.erase(op2);
			printf("%d %d\n", op.se, op2.se);
		}
		else {
			pii op = *s.begin(); s.erase(op);
			pii op2 = *s.upper_bound(pii(op.fi, n + 1)); s.erase(op2);
			printf("%d %d\n", op.se, op2.se);
			op.fi--, op2.fi--;
			if (op.fi) s.insert(op);
			if (op2.fi) s.insert(op2);
		}
	} 
	*/
	/*
	sort(lis + 1, lis + 1 + n);
	//reverse(lis + 1, lis + 1 + n);
	int ct = 0;
	rep(i, 1, n){
		int d = lis[i].fi, x = lis[i].se;
		num[x] = d - 1;
		while (d > 1) in[++ct] = x, d--; 
	}
	cerr << ct << endl;
	rep(i, 1, ct) cerr << in[i] << ' '; cerr << endl;
	process();
	*/
	return 0;
}
