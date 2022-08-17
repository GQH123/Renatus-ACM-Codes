#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 3020
#define maxm 
#define pii pair<ll, int>
#define fi first
#define se second
#define pb push_back
#define M 14717
using namespace std;

int n;
ll a[maxn];

struct hash_map{
	pii node[maxn];
	int nex[M];
	int has[M];
	int ct = 0;
	void insert(ll d, pii op){
		if (!has[d % M]) {has[d % M] = ++ct, node[ct] = op; return;}
		int now = has[d % M];
		while (1){
			if (!nex[now]){
				nex[now] = ++ct;
				node[ct] = op; 
				return;
			}
			now = nex[now];
		}
	}
	int get(ll d){
		if (!has[d % M]) return 1;
		int now = has[d % M];
		while (now){
			if (node[now].fi == d) return node[now].se;
			now = nex[now];
		}
		return 1;
	}
}mpp[maxn];


int main(){
	freopen("H.in", "r", stdin);
	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%lld", a + i);
	int mx = 0;
	per(i, n - 1, 1){
		rep(j, i + 1, n){
			ll d = a[j] - a[i];
			int dp = mpp[j].get(d);
			mpp[i].insert(d, pii(d, dp + 1));
			mx = max(mx, dp + 1);
			/*
				ll d = a[j] - a[i];
				if (!has[d % M]) has[d % M] = ++ct, node[ct] = pii(d, 1);
				int now = has[d % M];
				while (now){
					if (node[now].fi == d) {
						node[now].se++;
						mx = max(mx, node[now].se);
						break;
					}
					if (!nex[now]){
						nex[now] = ++ct;
						node[ct] = pii(d, 1); 
					}
					now = nex[now];
				}
			*/
		}
	}
	printf("%d", mx);
	return 0;
}

