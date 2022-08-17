#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn
#define maxm
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

inline bool judge(int x){
	int d = (int) sqrt(x);
	printf("%.52lf %d ", sqrt(x), d);
	return d * d == x;
}

int main(){
	
		//freopen(".in", "r", stdin);
	
	 
	if (judge(4)) printf("YES\n"); else printf("NO\n");
	
	if (judge(5)) printf("YES\n"); else printf("NO\n");
	
	if (judge(6)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(7)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(16)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(13)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(102476)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(205209)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(205289)) printf("YES\n"); else printf("NO\n");
	 
	if (judge(139876)) printf("YES\n"); else printf("NO\n");
		
	return 0;
}
