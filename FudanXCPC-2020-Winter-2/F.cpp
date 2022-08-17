#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxr 100000
#define maxn 2020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

int n;
int a[maxn];

int main(){
	/*
		#ifndef ONLINE_JUDGE
			freopen("F.in", "r", stdin);
		#endif
	*/
	while (1){
		scanf("%d", &n);
		if (n == 0) return 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		
	}
	return 0;
}
