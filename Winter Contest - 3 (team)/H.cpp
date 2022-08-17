#include <bits/stdc++.h>
#define rep(i, l, r) for(register int i = l; i <= r; i++)
#define per(i, r, l) for(register int i = r; i >= l; i--)
#define srep(i, l, r) for(register int i = l; i < r; i++)
#define sper(i, r, l) for(register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxr 1000000    // Maximum size of buffer
#define maxn 100020     // Maximum number of nodes
#define maxm 100020     // Maximum number of edges
#define FLOW int         // Define data type of flow
#define COST int         // Define data type of cost
using namespace std;

char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
    char ch = gc(); x = 0;
    while (!('0' <= ch && ch <= '9')) ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
}// Fast Read Module

const FLOW flow_inf = 1000000020;     // Macroes contained in climits
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
    rep(i, 1, all) vis[i] = 0, d[i] = flow_inf;
    he = ta = 0; spfa[++he] = S; d[S] = 0; vis[S] = 1;
    while (he != ta){
        int x = spfa[++ta]; vis[x] = 0;
        ta = (ta == maxn - 1) ? 0 : ta;
        // Single node may enter queue many times, so tail may reach maxn-1
        erep(i, x){
            if (!e[i].flow) continue;
            int op = e[i].to;
            if (d[op] > d[x] + e[i].cost){   
                d[op] = d[x] + e[i].cost, p[op] = i;
                // We should update p here, but not below
                if (!vis[op]) spfa[++he] = op, vis[op] = 1; 
                he = (he == maxn - 1) ? 0 : he;
                // Single node may enter queue many times, so head may reach maxn-1
            }
        } 
    }
    return d[T] != flow_inf;
}
bool f = 1;
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
    if (d[T] >= d[S]) {
    	f = 0;
    	return;
    }
    maxflow += flow, mincost += (d[T] - d[S]) * flow;
    
}
void MCMF(FLOW& maxflow, COST& mincost){
    while (f && SPFA()) Augment(maxflow, mincost);
}
inline void recover(){  
    rep(i, 1, all) h[i] = 0; cnt = 1; all = 0;
}
namespace Sample{
    void sample(){
        int x, y; FLOW z; COST w;
        read(n), read(m), S = 1 << 1, T = all = n << 1 | 1;
        // Don't forget to update variable all
        rep(i, 1, n) read(x), Add_Edge(i << 1, i << 1 | 1, flow_inf, -x);
        rep(i, 1, m) read(x), read(y), read(z), Add_Edge(x << 1 | 1, y << 1, z, 0);
        FLOW maxflow = 0; COST mincost = 0;
        MCMF(maxflow, mincost);
        printf("%d\n", -mincost); 
    }
}
int main(){Sample :: sample();}
