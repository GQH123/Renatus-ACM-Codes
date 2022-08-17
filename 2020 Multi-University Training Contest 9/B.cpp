#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 10000020
#define maxT 20020
#define lowbit(x) (x & -x)
using namespace std;

int p[maxn], son[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i, son[i] = cp;
		rep(j, 1, cp){
			int k = i * p[j];
			if (k >= maxn) break;
			vis[k] = 1;
			son[k] = j;
			if (i % p[j] == 0) break;
		}
	}
}

int ans[maxT];
struct ele{
	int n, m, id;
	ele(int n, int m) : n(n), m(m){}
	ele(){}
	bool operator < (const ele b) const{
		return m < b.m;
	}
}q[maxT];

int sum[maxn];
//bool havn[maxn];

int lis[maxn], cs = 0;
int bit[1 << 10];
void dep(int n){ 
	while (n > 1){
		int now = son[n];
		while (n > 1 && son[n] == now) n /= p[son[n]];
		lis[cs++] = now;
	} 
	bit[0] = 1, sum[1]++;
	srep(i, 1, (1 << cs)) bit[i] = bit[i ^ (1 << lowbit(i))] * p[lis[lowbit(i)]], sum[bit[i]]++; 
}

int root(int n){
	int ans = 1;
	while (n > 1){
		int now = son[n];
		while (n > 1 && son[n] == now) n /= p[son[n]];
		ans *= p[now];
	}
	return ans;
}

int main(){
	init();
	int T; scanf("%d", &T);
	int mx = 0;
	rep(i, 1, T){
		scanf("%d%d", &q[i].n, &q[i].m);
		mx = max(mx, q[i].m);
		q[i].n = root(q[i].n);
		//hav[root(n)] = 1;
	}
	rep(i, 1, mx) dep(i); 
	rep(i, 1, T) printf("%d\n", sum[q[i].n]); 
	/*
	rep(i, 1, T) scanf("%d%d", &q[i].n, &q[i].m), q[i].id = i;
	sort(q + 1, q + 1 + T);
	rep(i, 1, T) q[i].n = root(q[i].n), havn[q[i].n] = 1; 
	int last = 0;
	rep(i, 1, T){
		rep(j, last + 1, q[i].m) dep(j); 
		last = q[i].m;
	}
	rep(i, 1, T) ans[q[i].id] = sum[q[i].n];
	rep(i, 1, T) printf("%d\n", ans[i]); 
	*/
	return 0;
}
