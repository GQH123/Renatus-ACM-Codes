#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 300020
#define maxr 
using namespace std;

char win[] = "Make Byteland Great Again!";
char lose[] = "Fake Polls!";


int n, t, lis[maxn], cs = 0;
int main(){
	int x, y;
	scanf("%d%d", &n, &t);
	int ans = 0;
	rep(i, 1, n) {
		scanf("%d%d", &x, &y);
		if (x <= y) {ans++; continue;}
		lis[++cs] = (x - y + 1) / 2;
	}
	sort(lis + 1, lis + 1 + cs);
	rep(i, 1, cs){
		if (t < lis[i]) break;
		t -= lis[i];
		ans++;
	}
	if (ans > n - ans) puts(win);
	else puts(lose);
	return 0;
}
