#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define rerep(i, x) for (register int i = rGraph :: h[x]; i; i = rGraph :: e[i].next) 
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

#define maxn 50020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, k, S, T;
int w[maxn], u[maxn], marked[maxn];

namespace Graph{
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxn << 1];
	int cnt = 1, h[maxn], in[maxn], out[maxn];
	void Add_Edge(int x, int y) {
		e[++cnt] = edge(h[x], y);
		h[x] = cnt;
		in[y]++, out[x]++;
	}
}using namespace Graph;

namespace rGraph{
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxn << 1];
	int cnt = 1, h[maxn], in[maxn], out[maxn];
	void Add_Edge(int x, int y) {
		e[++cnt] = edge(h[x], y);
		h[x] = cnt;
		in[y]++, out[x]++;
	}
}

void recover(){
	rep(i, 1, n) in[i] = out[i] = h[i] = marked[i] = rGraph :: in[i] = rGraph :: out[i] = rGraph :: h[i] = 0; cnt = rGraph :: cnt = 1;
}

namespace NotsoNaive4{
	#define avi vector<int>
	int dfn[maxn], id[maxn], pa[maxn], semi[maxn], idom[maxn], p[maxn], mn[maxn]; avi g[maxn], be[maxn], dom[maxn]; int cnt;
	void minto(int& x, int y) {
		x = (x < y) ? x : y;
	}
	void dfs(int x) {
		dfn[x] = ++cnt; id[cnt] = x;
		for (auto i : g[x]) {
			if (!dfn[i]) { dfs(i); pa[dfn[i]] = dfn[x]; }
			be[dfn[i]].pb(dfn[x]);
		}
	}
	int get(int x) {
		if (p[x] != p[p[x]]) {
			if (semi[mn[x]] > semi[get(p[x])]) mn[x] = get(p[x]);
			p[x] = p[p[x]];
		}
		return mn[x];
	}
	void LT() {
		for (int i = cnt; i > 1; --i) {
			for (auto j : be[i]) minto(semi[i], semi[get(j)]);
			dom[semi[i]].pb(i);
			int x = p[i] = pa[i];
			for (auto j : dom[x])
				idom[j] = (semi[get(j)] < x ? get(j) : x);
			dom[x] = {};
		}
		for (int i = 2; i <= cnt; ++i) {
			if (idom[i] != semi[i]) idom[i] = idom[idom[i]];
			dom[id[idom[i]]].pb(id[i]);
		}
	}
	void build(int s, int n) {
		for (int i = 1; i <= n; ++i) {
			dfn[i] = id[i] = pa[i] = idom[i] = 0; dom[i] = be[i] = {};
			p[i] = mn[i] = semi[i] = i;
		}
		cnt = 0; dfs(s); LT();
	}
	bool leaf[maxn]; int c[maxn], acc = 0, fa[maxn]; vector<int> reg[maxn];
	
	set<int> g1[maxn], g2[maxn];
	
	
	int idx[maxn], siz[maxn], tim = 0;
	void dfsS(int x) {
		siz[x] = 1;
		idx[x] = ++tim;
		for (auto it: g2[x]) {
			dfsS(it);
			siz[x] += siz[it];
		}
	}
	
	int d[maxn];
	void dfsT(int x){
		for (auto it: g1[x]) {
			d[it] = d[x] + 1;
			dfsT(it); 
		}
	}
	
	
	int lis[maxn];
	/*
	bool cmp(const int i, const int j) {
		return d[i] > d[j];
	}
	*/
	int cs = 0;
	int _in[maxn];
	
	int que[maxn], head = 0, tail = 0;
	void topo_sort(){
		cs = 0; que[++head] = S;
		rep(i, 1, n) _in[i] = in[i];
		while (head > tail){
			int x = que[++tail];
			lis[++cs] = x;
			erep(i, x){
				int op = e[i].to;
				_in[op]--;
				if (!_in[op]) que[++head] = op;
			}
		}
	}
	
	bool tomark[maxn]; int sum[maxn], rsum[maxn];
	void recover(){
		rep(i, 1, n) fa[i] = c[i] = sum[i] = rsum[i] = in[i] = out[i] = dfn[i] = p[i] = id[i] = pa[i] = idom[i] = mn[i] = leaf[i] = tomark[i] = 0, reg[i].clear(), g[i].clear(), g1[i].clear(), g2[i].clear(), be[i].clear(), dom[i].clear();
		cnt = 0, acc = 0; 
	}
	
	//int dfn[maxn], id[maxn], pa[maxn], semi[maxn], idom[maxn], p[maxn], mn[maxn]; avi g[maxn], be[maxn], dom[maxn]; int cnt;
	//#define debug
	bool cmp(int l, int r) {
		return sum[l] > sum[r];
	}
	void work(){
		rep(x, 1, n){ 
			erep(i, x) {
				int op = e[i].to;
				g[op].pb(x); 
			}
		}
		build(T, n); 
		rep(i, 1, n) {
			for (auto it: dom[i]) {
				g1[i].insert(it);
			}
		}
		
		rep(i, 1, n) g[i].clear();
		rep(x, 1, n){
			erep(i, x) {
				int op = e[i].to;
				g[x].pb(op);
			}
		}
		build(S, n); 
		rep(i, 1, n) {
			for (auto it: dom[i]) {
				g2[i].insert(it);
			}
		}
		
		
		tim = 0; dfsS(S);
		d[T] = 0; dfsT(T);
			
		//rep(i, 1, n) lis[i] = i;
		//sort(lis + 1, lis + 1 + n, cmp);
		topo_sort();
		rep(i, 1, n) {
			int x = lis[i];
			//printf("%d %d %d\n", x, in[x], g1[x].size());
			//assert(in[x] >= g1[x].size());
			
			bool gooddd = 1;
			rerep(k, x){
				int op = rGraph :: e[k].to;
				if (!g1[x].count(op)){	
					gooddd = 0;
					break;
				}
			}
			
			int mil = n + 1, id = -1, mxr = -1;
			if (gooddd && in[x]) {
				for (auto it: g1[x]) {
					if (idx[it] < mil) mil = idx[it], mxr = idx[it] + siz[it] - 1, id = it;
					else if (idx[it] == mil) {
						if (idx[it] + siz[it] - 1 > mxr) mil = idx[it], mxr = idx[it] + siz[it] - 1, id = it;
					}
				}
				
				bool real_good = 1;
				for (auto it: g1[x]) {
					if (idx[it] < mil || idx[it] + siz[it] - 1 > mxr) {real_good = 0; break;}
				}
				//assert(milid != -1);
				if (real_good) {
					c[x] = c[id];
				}
				else c[x] = ++acc;
			}
			else c[x] = ++acc;
			
			reg[c[x]].pb(x);
		}
		
		rep(i, 1, acc) {
			for (auto it: reg[i]) sum[i] += w[it];
			rsum[i] = sum[i];
		}
		rep(i, 1, acc) lis[i] = i;
		sort(lis + 1, lis + 1 + acc, cmp);
		
		int ptr = 1, racc = acc, rest = n - k;
		per(i, acc, 1){
			if (reg[i].size() == 1 && !marked[reg[i][0]]) { 
				while (ptr <= acc && reg[ptr].size() > 1 && sum[ptr] * 10l <= (rsum[ptr] + w[reg[i][0]]) * 9l) ptr++;
				if (reg[ptr].size() > 1) {
					rsum[ptr] += w[reg[i][0]];
					reg[ptr].pb(reg[i][0]);
					racc--;
					rest--; 
					tomark[reg[i][0]] = 1;
					reg[i].clear();
				}
				else break;
			}
		}
		
		/*
		rep(i, 1, n) {
			if (dom[i].empty()) {leaf[i] = 1; continue;}
			//printf("%d", i); 
			for (auto it: dom[i]) fa[it] = i, in[it]++, out[i]++;//, printf(" %d", it); printf("\n");
		}
		*/
		
		printf("%d", rest);
		rep(i, 1, n) {
			if (!marked[i] && !tomark[i]) printf(" %d", i);
		}
		printf("\n");
		
		//dfs2(T, acc);
		
		/*
		rep(i, 1, n) {
			if (!leaf[i]) continue;
			int now = i; acc++;
			while (now && !cc[now] && now != T && now ) cc[now] = acc, reg[acc].pb(now), now = fa[now];
		}
		*/
		
		printf("%d\n", racc);
		rep(i, 1, acc) {
			if (reg[i].empty()) continue;
			printf("%d", (int)reg[i].size());
			for (auto it: reg[i]) printf(" %d", it);
			printf("\n");
		}
		
		recover();
		
	} 
}

int main(){
	int Case, x, y; read(Case); 
	while (Case--){
		read(n); rep(i, 1, n) read(w[i]);
		read(k); rep(i, 1, k) read(u[i]), marked[u[i]] = 1;
		read(m);
		rep(i, 1, m) {
			read(x, y);
			Add_Edge(x, y);
			rGraph :: Add_Edge(y, x);
		}
		rep(i, 1, n) if (!in[i]) {S = i; break;}
		rep(i, 1, n) if (!out[i]) {T = i; break;}
		assert(S == 1 && T == n);
		/*----------*/
		
		//Naive:: output();
		NotsoNaive4 :: work();
		recover();
	}
	return 0;
}

