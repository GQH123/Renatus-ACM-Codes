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
#define maxn 1000020
#define maxm
using namespace std;

int p[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int dep(int x){
	if (x == 1) return 1;
	int ct = 0; 
	rep(i, 1, cp) {
		if (1ll * p[i] * p[i] > 1ll * x) break;
		if (x % p[i] == 0) {
			ct++;
			while (x % p[i] == 0) x /= p[i];
		}
	}
	if (x > 1) ct++;
	return ct;
}


int main(){
	int n;
	init(); 
	/*
	rep(n, 1, 10000){
		if (n % 4 == 0) printf("%d : %d\n", n, (n == 4) ? (n - 1) : 1); 
		else if (n % 2 == 0) printf("%d : %d\n", n, (dep(n / 2) == 1) ? (n - 1) : 1); 
		else printf("%d : %d\n", n, (dep(n) == 1) ? (n - 1) : 1); 
	}
	*/
	
	while (scanf("%d", &n) == 1){
		if (n % 4 == 0) printf("%d\n", (n == 4) ? (n - 1) : 1); 
		else if (n % 2 == 0) printf("%d\n", (dep(n / 2) == 1) ? (n - 1) : 1); 
		else printf("%d\n", (dep(n) == 1) ? (n - 1) : 1); 
	}
	
	return 0;
}
