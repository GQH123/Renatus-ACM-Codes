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
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxa 256
#define maxn maxa * 4
#define maxm maxa * maxa * 4
#define maxs
#define maxb
#define inf 1000000000
#define eps
#define M 
#define ll long long int 

int w[maxa][maxa];

#define FLOW int
#define COST int
const FLOW flow_inf = INT_MAX;      // Macroes contained in climits
//const FLOW flow_inf = LONG_MAX;   // Macroes contained in climits
//const COST cost_inf = INT_MAX;    // Macroes contained in climits
//const COST cost_inf = LONG_MAX;   // Macroes contained in climits

int n, m, S, T, all;
struct edge{
    int next, to; FLOW flow; COST cost; 
    edge(int next, int to, FLOW flow, COST cost) : next(next), to(to), flow(flow), cost(cost){}
    edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, FLOW z, COST w){
    e[++cnt] = edge(h[x], y, z, w);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x, 0, -w);
    // Pay attention to parameters of reverse edge
    h[y] = cnt;
}

int p[maxn];            // Previous edge of nodes
int spfa[maxn];         // Queue of SPFA
int he = 0;             // Head of queue
int ta = 0;             // Tail of queue
COST d[maxn];           // Minimum cost of nodes
bool vis[maxn];         // Label for visit in SPFA

bool SPFA(){
    rep(i, 1, all) vis[i] = 0, d[i] = -1;
    he = ta = 0; spfa[++he] = S; d[S] = 0; vis[S] = 1;
    while (he != ta){
        int x = spfa[++ta]; vis[x] = 0;
        ta = (ta == maxn - 1) ? 0 : ta;
        // Single node may enter queue many times, so tail may reach maxn-1
        erep(i, x){
            if (!e[i].flow) continue;
            int op = e[i].to;
            if (d[op] == -1 || d[op] > d[x] + e[i].cost){   
                d[op] = d[x] + e[i].cost, p[op] = i;
                // We should update p here, but not below
                if (!vis[op]) spfa[++he] = op, vis[op] = 1; 
                he = (he == maxn - 1) ? 0 : he;
                // Single node may enter queue many times, so head may reach maxn-1
            }
        } 
    }
    return d[T] != -1;
}
void Augment(FLOW& maxflow, COST& mincost){ 
    int x = T; FLOW flow = flow_inf;
    while (x != S){ 
        int k = p[x];
        flow = min(flow, e[k].flow);
        x = e[k ^ 1].to;
    }
    x = T; 
    while (x != S){
        int k = p[x];
        e[k].flow -= flow, e[k ^ 1].flow += flow;
        x = e[k ^ 1].to;
    }
    maxflow += flow, mincost += (d[T] - d[S]) * flow;
}
void MCMF(FLOW& maxflow, COST& mincost){
    while (SPFA()) Augment(maxflow, mincost);
}
inline void recover(){  
    rep(i, 1, all) h[i] = 0; cnt = 1; all = 0;
}

int res[maxa][maxa];
int rec[maxn];
int main(){
    while (scanf("%d%d", &n, &m) == 2) {
        int mx = 0;
        rep(i, 1, n) rep(j, 1, m) scanf("%d", &w[i][j]), mx = max(mx, w[i][j]);
        
        
        rep(x, 1, n) {
            S = n + m + 1, T = n + m + 2, all = n + m + 4;
            int K1 = n + m + 3, K2 = n + m + 4;
            rep(i, 1, n) rep(j, 1, m) Add_Edge(i, j + n, 1, -w[i][j]);
            rep(i, 1, n) {
                if (i == x) continue;
                Add_Edge(S, i, 1, 0);
            }
            Add_Edge(1 + n, T, 0, 0);
            rec[1] = cnt - 1;
            rep(i, 2, m) {
                Add_Edge(i + n, T, 1, 0);
                rec[i] = cnt - 1;
            }
            
            int maxflow = 0, mincost = 0;
            MCMF(maxflow, mincost); 
            //Add_Edge(S, K2, inf, 0);
            
            S = K1, T = K2;
            
            int h1 = h[K1], h2 = h[K2];
            
            rep(y, 1, m){
                res[x][y] = -mincost; //+ 1ll * (mx + 1) * min(n - 1, m - 1);
                
                if (y == m) break;
                int hh1 = h[n + y + 1], hh2 = h[n + y];
                Add_Edge(K1, n + y + 1, 1, 0); 
                Add_Edge(n + y, K2, 1, 0);
                MCMF(maxflow, mincost);
                
                
                cnt -= 4;
                h[K1] = h1, h[K2] = h2;
                h[n + y + 1] = hh1, h[n + y] = hh2;
                
                if (e[cnt + 1].flow == 0) {
                    e[rec[y]].flow = 1, e[rec[y] ^ 1].flow = 0;
                    e[rec[y + 1]].flow = 0, e[rec[y + 1] ^ 1].flow = 1;
                }
                
                
                /*
                cnt -= 4;
                h[K1] = h1, h[K2] = h2;
                h[n + y + 1] = hh1, h[n + y] = hh2;
                */
                // S = K1, T = K2; 
            }
            printf("%d\n",x);
            recover();
        }
        
        
        rep(i, 1, n) {rep(j, 1, m) printf("%d ", res[i][j]); printf("\n");}
    }
	return 0;
}

