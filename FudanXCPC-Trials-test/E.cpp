#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 2000020
#define ll long long int 
#define pli pair<ll, int> 
#define fi first
#define se second
using namespace std;


int n, a[maxn];
char s[maxn];
int num[9];
ll arr[9][9];
ll P[9][9], C[9][9];


//bool vis[9]; 

struct ele{
	int lis[9];
	bool operator < (const ele& b) const{
		rep(i, 1, 8) {
			if (lis[i] != b.lis[i]) return lis[i] < b.lis[i];
		}
		return false;
	}
}op;

int lis[9], rlis[9];

map<ele, int> id;
struct edge{
	int next, to;
	ll len;
	edge(int next, int to, ll len) : next(next), to(to), len(len) {}
	edge(){}
}e[maxn];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, ll w){
	e[++cnt] = edge(h[x], y, w);
	h[x] = cnt;
}

void add(int x){
	rep(i, 1, 8) rep(j, i + 1, 8){
		swap(op.lis[i], op.lis[j]);
		//assert(id.count(op));
		Add_Edge(x, id[op], C[op.lis[i]][op.lis[j]]);
		swap(op.lis[i], op.lis[j]); 
	}
}

ll d[maxn];
bool vis[maxn];
priority_queue<pli> pq;
void Dij(){
	int ct = 0;
	rep(i, 1, 8) op.lis[i] = i; id[op] = ++ct;
	while (next_permutation(op.lis + 1, op.lis + 1 + 8)){
		id[op] = ++ct;
	}
	ct = 0;
	rep(i, 1, 8) op.lis[i] = i; ++ct, add(ct);
	while (next_permutation(op.lis + 1, op.lis + 1 + 8)){
		++ct, add(ct);
	}
	rep(i, 1, ct) d[i] = -1;
	
	d[1] = 0;
	pq.push(pli(0, 1));
	while (!pq.empty()){
		pli op = pq.top(); pq.pop();
		if (vis[op.se]) continue;
		int x = op.se;
		vis[x] = 1;
		erep(i, x){	
			int op = e[i].to;
			if (d[op] == -1 || e[i].len < d[op] - d[x]){
				d[op] = d[x] + e[i].len;
				pq.push(pli(-d[op], op));
			}
		}
	}
}


int main(){
	scanf("%d", &n); scanf("%s", s + 1);
	rep(i, 1, 8) rep(j, 1, 8) scanf("%lld", &P[i][j]);
	rep(i, 1, 8) rep(j, 1, 8) scanf("%lld", &C[i][j]);
	rep(i, 1, n) a[i] = s[i] - '0';
	per(i, n, 1) {	
		num[a[i]]++;
		rep(j, 1, 8) arr[a[i]][j] += num[j]; 
	}
	ll ans = -1;
	Dij();
	rep(i, 1, 8) lis[i] = i, rlis[lis[i]] = i; 
	int ct = 0;
	while (1){	
		ct++;	
		ll res = d[ct];  
		rep(i, 1, 8) {
			srep(j, 1, i) {
				res += P[i][j] * arr[rlis[i]][rlis[j]];
			}
		}
		//rep(i, 1, 8) cerr << lis[i] << ' '; cerr << endl;
		ans = (ans == -1) ? res : min(ans, res);
		if (!next_permutation(lis + 1, lis + 1 + 8)) break; 
		
		rep(i, 1, 8) rlis[lis[i]] = i;
	}
	//cerr << ct << endl;
	printf("%lld\n", ans);
	return 0;
}
