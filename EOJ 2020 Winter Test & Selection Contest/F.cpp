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
#define lowbit(x) (x & -x) 
using namespace std;

const int inf = 2000000020;

int main(){
	
		//freopen(".in", "r", stdin);
		
	int w, h, W, H; 
	scanf("%d%d%d%d", &W, &H, &w, &h);
	int _w = w, _h = h;
	int ans1 = 0;
	if (W < w || H < h) ans1 = inf;
	else {
		while (W > w) w <<= 1, ans1++;
		while (H > h) h <<= 1, ans1++; 
	}
	
	w = _w, h = _h;
	swap(W, H);
	int ans2 = 0;
	if (W < w || H < h) ans2 = inf;
	else {
		while (W > w) w <<= 1, ans2++;
		while (H > h) h <<= 1, ans2++; 
	}
	
	if (ans1 == inf && ans2 == inf) printf("-1");
	else printf("%d", min(ans1, ans2));
	return 0;
}
