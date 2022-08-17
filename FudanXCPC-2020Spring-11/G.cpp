#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 620
#define maxr 20000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; 
	while (!('0' <= ch && ch <= '9')) ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}


int n;
pii a[maxn][maxn];

int d[maxn], cd = 0;
void dep(){
	rep(i, 1, n) if (n % i == 0) d[++cd] = i; 
}

int pri[maxn];
int _pri[maxn];

vector<int> ss[maxn]; 
int id[maxn];

bool cmp(const int i, const int j){
	return _pri[i] > _pri[j]; 
}

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

int ans[maxn];
int num[maxn]; 
int main(){ 
	int T = 0;
	while (read(n), n){
		printf("Case #%d: ", ++T);
		rep(i, 1, n) rep(j, 1, n) read(a[i][j].fi), read(a[i][j].se); 
		dep();
		rep(i, 0, n) num[i] = 0;
		rep(i, 1, n) ss[i].clear(); 
		rep(i, 1, n){
			int ct = 0;
			rep(j, 1, n) {
				if (!num[a[i][j].se]) ct++;
				num[a[i][j].se]++;
			}
			pri[i] = ct;
			rep(k, 0, n) num[k] = 0;
			
			ct = 0;
			rep(j, 1, n) {
				if (!num[a[i][j].fi]) ct++;
				num[a[i][j].fi]++;
			}
			_pri[i] = ct;
			rep(k, 0, n) num[k] = 0;
			
			ss[pri[i]].push_back(i);
		} 
		rep(i, 1, n) if (!ss[i].empty()) sort(ss[i].begin(), ss[i].end(), cmp);
		srep(i, 0, n){
			int d = gcd(i, n);
			if (!d) d = n;
			id[*ss[n / d].rbegin()] = i;
			ss[n / d].pop_back();
		}
		int flag = -1;
		rep(j, 1, n){ 
			bool f1 = 1;
			int ct = 0;
			rep(i, 1, n){
				if (a[i][j].fi != a[1][j].fi) {
					f1 = 0;
					break;
				} 
				if (!num[a[i][j].se]) ct++;
				num[a[i][j].se]++; 
			}
			if (!f1 || ct != n) {
				rep(k, 0, n) num[k] = 0;
				continue;
			}
			flag = j;
			rep(k, 0, n) num[k] = 0;
			break;
		}
		rep(i, 1, n) ans[id[i]] = a[i][flag].se; 
		srep(i, 0, n - 1) printf("%d ", ans[i]);
		printf("%d", ans[n - 1]);
		printf("\n");
		cd = 0; 
	}
	return 0;
}
