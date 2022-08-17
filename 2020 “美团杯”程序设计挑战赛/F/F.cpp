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
#define maxn
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int a[100020], b[200], num[305];
int main(){
	int ct = 0;
	while (++ct, scanf("%d", a + ct) == 1);
	ct--;
	rep(i, 1, ct) printf("%d ", a[i]); printf("\n");
	int k = 7;
	rep(i, k, ct){
		rep(j, 1, k) b[j] = a[i - k + j];
		bool f = 0;
		rep(ii, 1, k) rep(iii, ii + 1, k) if (b[ii] == b[iii]) f = 1;
		if (f) continue;
		//b[1] = a[i - 2], b[2] = a[i - 1], b[3] = a[i];
		//if (b[1] == b[2] || b[2] == b[3] || b[3] == b[1]) continue;
		int cnt = 0;
		rep(j, 1, ct - k + 1){
			bool f = 1;
			rep(jj, 1, k) if (a[j + jj - 1] != b[jj]) {f = 0; break;}
			//if (a[j] == b[1] && a[j + 1] == b[2] && a[j + 2] == b[3]) cnt++;
			if (f) cnt++;
		}
		if (cnt > 1) {rep(i, 1, k) printf("%d ", b[i]); printf(": %d \n", cnt);}
		//if (cnt > 1) printf("%d %d %d : %d %d %d\n", i - 2, i - 1, i, b[1], b[2], b[3]);
	}
	
	rep(i, 1, ct) num[a[i]]++; 
	int mx = 0;
	rep(i, 0, 255) if (num[i] > mx) mx = num[i];
	rep(i, 0, 255) if (num[i] == mx) printf("%d\n", i); 
	
	srep(i, 1, ct){
		if (a[i] == a[i + 1]) printf("%d %d\n", a[i], a[i + 1]);
	}
	
	
	set<int> s;
	rep(i, 1, ct - 8){
		s.clear();
		rep(j, i, i + 8) s.insert(a[j]);
		if (s.size() == 7 && a[i + 1] == a[i + 6] && a[i + 3] == a[i + 8]) {
			rep(j, i, i + 8) printf("%d ", a[j]); printf("\n");
		}
	}
	
	rep(i, 1, ct - 6){
		s.clear();
		rep(j, i, i + 6) s.insert(a[j]);
		if (s.size() == 7) {
			rep(j, i, i + 6) printf("%d ", a[j]); printf("\n");
		}
	}
	
	return 0;
}
