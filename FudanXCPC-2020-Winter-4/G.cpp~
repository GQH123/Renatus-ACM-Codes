#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
#define pb push_back
#define maxr 100000
#define maxn 30020
#define maxall 3000020
#define maxm 10000020
#define M 1000000007
#define end END
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

int n, m;
int s[maxn];

int ct = 0;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxall];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
}
vector<int> end[maxn];
int scc[maxall];
ll times[maxall];
ll dp[maxn];
int in[maxall];
int v[maxall];

int bfs[maxn];
int head = 0, tail = 0;
priority_queue<pli> pq2;
int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("G.in", "r", stdin);
		#endif
		
	int x, l, op;
	read(n), read(m);
	ct = n;
	rep(i, 1, n){
		read(s[i]);
		rep(j, 1, s[i]) end[i].pb(ct + j), scc[ct + j] = i;
		rep(j, 1, s[i]){
			read(l);
			rep(k, 1, l) read(x), Add_Edge(x + ct, j + ct), in[j + ct]++;
			read(op);
			read(v[ct + j]); 
			if (op == 1){
				v[ct + j] = -v[ct + j];
				Add_Edge(-v[ct + j], i), in[i]++;
			}
		}
		ct += s[i];
	}
	rep(i, 1, n) if (!in[i]) bfs[++head] = i;  
	while (head > tail) {
		int x = bfs[++tail];
		srep(i, 0, s[x]){
			int y = end[x][i];
			if (!in[y]) {
				if (v[y] >= 0) pq2.push(pli(-v[y], y));
				else pq2.push(pli(-(dp[-v[y]] + 1), y));
			}
		}
		while (!pq2.empty()) {
			pli _k = pq2.top(); pq2.pop();
			int _x = _k.se;
			dp[x] = -_k.fi;
			erep(i, _x){
				int _y = e[i].to;
				in[_y]--;
				if (!in[_y]) {
					ll d = -_k.fi;
					if (v[_y] >= 0) d += v[_y];
					else d += dp[-v[_y]] + 1;
					pq2.push(pli(-d, _y));
				}
			}
		}
		erep(i, x){
			int y = e[i].to;
			in[y]--;
			if (!in[y]) bfs[++head] = y;
		}
	}
	rep(i, 1, m){
		read(x);
		printf("%lld\n", dp[x] % M);
	}
	return 0;
}
