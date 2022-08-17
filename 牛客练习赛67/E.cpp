#include <bits/stdc++.h>
#define maxn 300020
#define maxm
#define maxb
#define maxr 200000
#define maxs
#define M 
#define uint unsigned int 
#define pii pair<int, int>
#define pli pair<ll, int>
#define pdd pair<double, double>
#define uint unsigned int
#define ull unsigned long long int
#define ll long long int 
#define lowbit(x) x & -x
#define fi first
#define se second
#define pb push_back
#define next NEXT
#define hash HASH
#define ls ch[x][0]
#define rs ch[x][1]
#define pi 3.141592653589793
#define ei 2.718281828459045
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
//#define ONLINE_JUDGE
//#define DEBUG
using namespace std;

char *p1, *p2, buffer[maxr];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
    x = f ? x : -x;
}

int n;
struct edge{
	int next, to; ll len;
	edge(int next, int to, ll len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn * 40];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y, ll z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
}

ll d[maxn];
bool vis[maxn];
priority_queue<pli> pq;
void Dij(){	
	rep(i, 1, n + 100) vis[i] = 0, d[i] = -1;
	d[1 + 32] = 0;
	pq.push(pli(0, 1 + 32));
	while (!pq.empty()){
		pli u = pq.top(); pq.pop();
		if (vis[u.se]) continue;
		vis[u.se] = 1;
		int x = u.se;
		erep(i, x){	
			int op = e[i].to;
			if (d[op] == -1 || d[op] > d[x] + e[i].len){
				d[op] = d[x] + e[i].len;
				pq.push(pli(-d[op], op));
			}
		}
	}
	if (d[n + 32] == -1) printf("Impossible\n");
	else printf("%lld\n", d[n + 32]);
}

int main(){
    int T;
    uint x;
    read(T);
    while (T--){
    	read(n); 
    	rep(i, 1, n){
    		read(x);
    		rep(j, 0, 31){
    			if (x & (1ll << j)) {
    				Add_Edge(i + 32, j + 1, 1ll << j);
    				Add_Edge(j + 1, i + 32, 0);
    			}
    		}
    	}
    	Dij();
    	rep(i, 1, n + 100) h[i] = 0; cnt = 1;
    }
    return 0;
}
