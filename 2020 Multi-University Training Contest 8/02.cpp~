#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxr 20000000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++) 
#define maxn 2000020
using namespace std;

const int inf = 2000000000;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	x = 0; char ch = gc(); bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
} 

int n, L, R;
int a[maxn], dp[maxn], pre[maxn];


struct pii{
	int fi, se, id;
	pii(int fi, int se, int id) : fi(fi), se(se), id(id){}
	pii(){}
	bool operator < (const pii b) const{
		/*
		int f1, f2;
		if (fi < 0) f1 = -1;
		else if (fi == 0) f1 = 0;
		else f1 = 1;
		
		if (b.fi < 0) f2 = -1;
		else if (b.fi == 0) f2 = 0;
		else f2 = 1;
		
		if (f1 != f2) return fi < b.fi;
		return se < b.se;
		*/
		return (fi == b.fi) ? se < b.se : fi < b.fi;
	}
};
set<pii> s; int offset = 0;
set<pii> :: iterator it, _it;
//(segsum + offset, dp);
pii rec[maxn];
bool del[maxn];
int main(){
	int T; read(T);
	while (T--){
		s.clear(); offset = 0;
		read(n), read(L), read(R);
		del[0] = 0; rep(i, 1, n) del[i] = 0, read(a[i]), pre[i] = pre[i - 1] + a[i];
		dp[0] = 0; srep(i, 1, L) dp[i] = -inf;
		rep(i, L, n){
			offset += a[i];
			if (i - R - 1 >= 0) if (!del[i - R - 1]) s.erase(s.lower_bound(rec[i - R - 1])); 
			rec[i - L] = pii(pre[i] - pre[i - L] - offset, dp[i - L], i - L);
			//s.clear();
			it = s.lower_bound(rec[i - L]);
			if (it != s.end()){
				if (it -> fi == rec[i - L].fi) {
					del[i - L] = 1; 
				}
				else {
					while (it != s.begin()){
						--it;
						if (it -> se <= rec[i - L].se) {
							del[it -> id] = 1;
							if (it != s.begin()) _it = it, it--, s.erase(_it);///////////////
							else {s.erase(it); break;}
						}
					}
					s.insert(rec[i - L]);
				}
			}
			else s.insert(rec[i - L]);
			
			int& ans = dp[i]; ans = -inf;
			it = s.begin();
			if (it != s.end()){ 
				if (it -> fi + offset < 0) ans = max(ans, it -> se - 1); 
			} 
			it = s.lower_bound(pii(-offset, -inf, -inf));
			if (it != s.end()){ 
				if (it -> fi + offset == 0) ans = max(ans, it -> se);
			}
			it = s.lower_bound(pii(-offset + 1, -inf, -inf));
			if (it != s.end()){ 
				if (it -> fi + offset > 0) ans = max(ans, it -> se + 1);
			}
		}
		//rep(i, 1, n) cerr << dp[i] << ' ';
		//cerr << endl;
		printf("%d\n", dp[n]); 
	}
	return 0;
}
