#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first 
#define se second 
#define maxr 100019
#define maxn 219
#define maxm
#define maxs 200019
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n;
struct ele{
	char name[20];
	int hp, at, df;
	void read(){
		scanf("%s", name);
		scanf("%d%d%d", &hp, &at, &df);
	}
}p[maxn];

bool judge(int i, int j){//if i wins against j
	if (p[i].at <= p[j].df) return false;
	if (p[j].at <= p[i].df) return true;
	int r1 = (p[j].hp - 1) / (p[i].at - p[j].df) + 1;
	int r2 = (p[i].hp - 1) / (p[j].at - p[i].df) + 1;
	if (r1 < r2) return true;
	else return false;
}

int out[maxs][3];
int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("B.in", "r", stdin);
		#endif
	
	scanf("%d", &n);
	rep(i, 1, n) p[i].read();
	int ans = 0;
	rep(i, 1, n){
		rep(j, i + 1, n){
			rep(k, j + 1, n){
				if ((judge(i, j) && judge(j, k) && judge(k, i)) || (judge(j, i) && judge(i, k) && judge(k, j))){
					ans++;
					out[ans][0] = i, out[ans][1] = j, out[ans][2] = k;
				}
			}
		}
	}
	printf("%d\n", ans);
	rep(i, 1, ans) printf("%s %s %s\n", p[out[i][0]].name, p[out[i][1]].name, p[out[i][2]].name); 
	return 0;
}
