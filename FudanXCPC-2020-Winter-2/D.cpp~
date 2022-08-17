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
#define maxr 100000
#define maxn 220
#define maxm 9020
#define Base 2333
#define M 1000000007
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000020;

int n, m;

ll Hash(char* s){
	int n = strlen(s + 1);
	ll hash = 0;
	rep(i, 1, n) hash = (hash * Base % M + s[i]) % M;
	return hash;
}

map<ll, int> find_node;

struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

/*bool vis[maxn];
int d[maxn];
priority_queue<pii> pq;
void Dij(int s){
	rep(i, 0, n) d[i] = inf;
	pq.push(pii(0, s));
	//d[s] = 0, vis[s] = 1;
	while (!pq.empty()) {
		pii op = pq.top(); pq.pop();
		int x = op.se;
		if (vis[x]) continue;
		vis[x] = 1, d[x] = -op.fi;
		erep(i, x){
			int u = e[i].to;
			if (d[u] > d[x] + e[i].len) {
				d[u] = d[x] + e[i].len;
				pq.push(pii(-d[u], u));
			}
		}
	}
}*/

int d[maxn];
int bfs[maxn];
int head = 0, tail = 0;
void BFS(int s){
	rep(i, 1, n) d[i] = inf;
	bfs[++head] = s;
	while (head != tail){
		int x = bfs[++tail];
		erep(i, x){
			int op = e[i].to;
			if (d[op] < inf) continue;
			d[op] = d[x] + 1;
			bfs[++head] = op;
		}
	}
}

int lis[maxn];
bool cmp(int i, int j){
	return d[i] < d[j];
}
ll solve(){
	ll ans = 0;
	rep(i, 1, n) lis[i] = i;
	sort(lis + 1, lis + 1 + n, cmp);
	rep(i, 1, n){
		int x = lis[i];
		int mic = inf;
		erep(i, x){
			int op = e[i].to;
			if (d[op] == d[x] - 1) mic = min(mic, e[i].len); 
		}
		ans += mic;
	}
	return ans;
}

char s[25], t[25], eng[] = "REnglish";

int main(){
	
		#ifndef ONLINE_JUDGE
			freopen("D.in", "r", stdin);
		#endif
	
	int x, y, z;
	scanf("%d%d", &n, &m);
	find_node[Hash(eng)] = 0;
	rep(i, 1, n) {
		scanf("%s", s + 1);
		ll hash = Hash(s);
		find_node[hash] = i;
	}
	rep(i, 1, m){
		scanf("%s%s", s + 1, t + 1);
		//if (i == 1) printf("%lld %lld\n", Hash(s), Hash(eng));
		scanf("%d", &z);
		x = find_node[Hash(s)];
		y = find_node[Hash(t)];
		Add_Edge(x, y, z);
		//printf("%d %d %d\n", x, y, z);
	}
	BFS(find_node[Hash(eng)]);
	rep(i, 1, n) {
		if (d[i] == inf) {
			printf("Impossible\n");
			return 0;
		}
		//ans += d[i];
	}
	printf("%lld", solve());
	/*Dij(find_node[Hash(eng)]);
	ll ans = 0;
	rep(i, 1, n) {
		if (d[i] == inf) {
			printf("Impossible\n");
			return 0;
		}
		ans += d[i];
	}
	printf("%lld", ans);*/
	return 0;
}
