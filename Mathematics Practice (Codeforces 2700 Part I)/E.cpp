#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 5020
#define maxa 1000020
#define maxnode 15000000
#define ll long long int 
#define div DIV
#define pb push_back
using namespace std;

bool ok[maxa];
//set<int> div[maxa];

int n, k, a[maxn];
int h[maxa], t[maxa];
int nex[maxnode];
int v[maxnode];
int ct = 0;
int s[maxa];
int vis[maxa]; 
bool tvis[maxa];
int st[maxa], cs = 0;
int main(){
	
		freopen("E.in", "r", stdin); 
	 
	
	scanf("%d%d", &n, &k);
	int mx = 0, x, y, z, si, last;
	rep(i, 1, n) scanf("%d", a + i), mx = max(mx, a[i]);
	rep(i, max(1, n - k), mx + 1) {
		for (register int j = i; j <= mx + 1; j += i) {
			if (!h[j]) h[j] = t[j] = ++ct, v[ct] = i;
			else {t[j] = nex[t[j]] = ++ct, v[t[j]] = i;} 
		}
	}
	rep(i, 1, n){
		srep(j, 1, i){
			x = abs(a[i] - a[j]);
			y = h[x];
			while (y) {
				z = v[y];
				if (!tvis[z]) vis[z]++, tvis[z] = 1, st[++cs] = z;  
				y = nex[y]; 
			}
		}
		while (cs) {
			x = st[cs--], tvis[x] = 0;  
			if (vis[x] > k){
				for (register int j = x; j <= mx + 1; j += x){
					y = h[j];
					if (v[y] == x) h[j] = nex[h[j]];
					else {
						while (v[y] ^ x) last = y, y = nex[y];
						nex[last] = nex[y];
					}
				}
			}
		}
	}  
	rep(i, max(1, n - k), mx + 1){
		if (vis[i] <= k) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
