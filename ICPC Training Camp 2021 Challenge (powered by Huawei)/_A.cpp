namespace Naive{
	void output(){	
		printf("%d", n - k);
		rep(i, 1, n) {
			if (!marked[i]) printf(" %d", i);
		}
		printf("\n");
		
		printf("%d\n", n);
		rep(i, 1, n) printf("1 %d\n", i);
	}
}

namespace NotsoNaive{	
	vector<int> reg[maxn];
	int c[maxn], acc = 1;
	void dfs(int x, int& cc) {
		if (c[x]) return;
		c[x] = cc;
		reg[cc].pb(x);
		if (out[x] > 1) {
			erep(i, x) {
				int op = e[i].to;
				if (c[op]) continue;
				dfs(op, ++cc);
			}
		}
		else {
			erep(i, x) {
				int op = e[i].to;
				if (c[op]) continue;
				if (in[op] > 1) dfs(op, ++cc);
				else dfs(op, cc);
			}
		}
	}
	void recover(){
		rep(i, 1, n) c[i] = 0;
		rep(i, 1, acc) reg[i].clear();
		acc = 1;
	} 
	void work(){
		dfs(1, acc);
		printf("%d", n - k);
		rep(i, 1, n) {
			if (!marked[i]) printf(" %d", i);
		}
		printf("\n");
		//acc = 0; rep(i, 1, n) acc = max(acc, c[i]);
		printf("%d\n", acc);
		rep(i, 1, acc) {
			assert(!reg[i].empty());
			printf("%d", (int)reg[i].size());
			for (auto it: reg[i]) printf(" %d", it);
			printf("\n");
		}
		recover();
	}
}

namespace NotsoNaive2{
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
			dfn[i] = 0; dom[i] = be[i] = {};
			p[i] = mn[i] = semi[i] = i;
		}
		cnt = 0; dfs(s); LT();
	}
	bool leaf[maxn]; int c[maxn], in[maxn], out[maxn], acc = 1, fa[maxn]; vector<int> reg[maxn];
	
	
	
	void dfs2(int x, int& cc) {
		if (c[x]) return;
		c[x] = cc;
		reg[cc].pb(x);
		if (out[x] > 1) {
			for (auto op: dom[x]){ 
				if (c[op]) continue;
				dfs2(op, ++cc);
			}
		}
		else {
			for (auto op: dom[x]){ 
				if (c[op]) continue;
				if (in[op] > 1) dfs2(op, ++cc);
				else dfs2(op, cc);
			}
		}
	}
	
	void recover(){
		rep(i, 1, n) fa[i] = c[i] = in[i] = out[i] = dfn[i] = p[i] = id[i] = pa[i] = idom[i] = mn[i] = leaf[i] = 0, reg[i].clear(), g[i].clear(), be[i].clear(), dom[i].clear();
		cnt = 0, acc = 1; 
	}
	
	//int dfn[maxn], id[maxn], pa[maxn], semi[maxn], idom[maxn], p[maxn], mn[maxn]; avi g[maxn], be[maxn], dom[maxn]; int cnt;
	void work(){
		rep(x, 1, n){
			erep(i, x) {
				int op = e[i].to;
				g[op].pb(x);
			}
		}
		build(T, n);
		rep(i, 1, n) {
			if (dom[i].empty()) {leaf[i] = 1; continue;}
			//printf("%d", i); 
			for (auto it: dom[i]) fa[it] = i, in[it]++, out[i]++;//, printf(" %d", it); printf("\n");
		}
		
		printf("%d", n - k);
		rep(i, 1, n) {
			if (!marked[i]) printf(" %d", i);
		}
		printf("\n");
		
		dfs2(T, acc);
		
		/*
		rep(i, 1, n) {
			if (!leaf[i]) continue;
			int now = i; acc++;
			while (now && !cc[now] && now != T && now ) cc[now] = acc, reg[acc].pb(now), now = fa[now];
		}
		*/
		
		printf("%d\n", acc);
		rep(i, 1, acc) {
			assert(!reg[i].empty());
			printf("%d", (int)reg[i].size());
			for (auto it: reg[i]) printf(" %d", it);
			printf("\n");
		}
		
		recover();
		
	} 
}

namespace NotsoNaive3{
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
			dfn[i] = 0; dom[i] = be[i] = {};
			p[i] = mn[i] = semi[i] = i;
		}
		cnt = 0; dfs(s); LT();
	}
	bool leaf[maxn]; int c[maxn], acc = 1, fa[maxn]; vector<int> reg[maxn];
	
	bool tmpmark[maxn];
	void submark(int x, int end) {
		if (tmpmark[x]) return;
		tmpmark[x] = 1;
		if (x == end) return;
		erep(i, x) {
			int op = e[i].to;
			submark(op, end);
		}
	}
	bool subjudge(int x, int end) { 
		if (x == end) return true; 
		rerep(i, x) {
			int op = rGraph :: e[i].to;
			if (!tmpmark[op]) return false;
		}
		erep(i, x){
			int op = e[i].to;
			if (!subjudge(op, end)) return false;
		} 
		return true;
	}
	/*
	void undo_submark(int x, int end){
		if (!tmpmark[x]) return;
		tmpmark[x] = 0;
		if (x == end) return;
		erep(i, x) {
			int op = e[i].to;
			submark(op, end);
		}
	}
	*/
	
	void dfs2(int x, int& cc) {
		if (c[x]) return;
		c[x] = cc;
		reg[cc].pb(x);
		
		bool good = 0; int end = -1;
		if (x != T && fa[x] != T) {
			end = fa[x]; 
			submark(x, end);
			if (subjudge(x, end)) {
				rep(i, 1, n) {
					if (i != end && tmpmark[i] && !c[i]) {
						c[i] = cc;
						reg[cc].pb(i);
					} 
				}
				good = 1;
			}
			rep(i, 1, n) tmpmark[i] = 0; 
		}
		if (good) dfs2(end, cc);
		else {
			if (out[x] > 1) {
				erep(i, x) {
					int op = e[i].to;
					if (c[op]) continue;
					dfs2(op, ++cc);
				}
			}
			else {
				erep(i, x) {
					int op = e[i].to;
					if (c[op]) continue;
					if (in[op] > 1) dfs2(op, ++cc);
					else dfs2(op, cc);
				}
			}
		}
	}
	
	void recover(){
		rep(i, 1, n) fa[i] = c[i] = in[i] = out[i] = dfn[i] = p[i] = id[i] = pa[i] = idom[i] = mn[i] = leaf[i] = 0, reg[i].clear(), g[i].clear(), be[i].clear(), dom[i].clear();
		cnt = 0, acc = 1; 
	}
	
	//int dfn[maxn], id[maxn], pa[maxn], semi[maxn], idom[maxn], p[maxn], mn[maxn]; avi g[maxn], be[maxn], dom[maxn]; int cnt;
	void work(){
		rep(x, 1, n){
			erep(i, x) {
				int op = e[i].to;
				g[op].pb(x);
			}
		}
		build(T, n);
		rep(i, 1, n) {
			if (dom[i].empty()) {leaf[i] = 1; continue;}
			//printf("%d", i); 
			for (auto it: dom[i]) fa[it] = i;//, in[it]++, out[i]++;//, printf(" %d", it); printf("\n");
		}
		
		printf("%d", n - k);
		rep(i, 1, n) {
			if (!marked[i]) printf(" %d", i);
		}
		printf("\n");
		
		dfs2(S, acc);
		
		/*
		rep(i, 1, n) {
			if (!leaf[i]) continue;
			int now = i; acc++;
			while (now && !cc[now] && now != T && now ) cc[now] = acc, reg[acc].pb(now), now = fa[now];
		}
		*/
		
		printf("%d\n", acc);
		rep(i, 1, acc) {
			assert(!reg[i].empty());
			printf("%d", (int)reg[i].size());
			for (auto it: reg[i]) printf(" %d", it);
			printf("\n");
		}
		
		recover();
		
	}
	
}
