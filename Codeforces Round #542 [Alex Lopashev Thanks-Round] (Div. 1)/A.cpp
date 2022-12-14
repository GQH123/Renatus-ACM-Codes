#include <bits/stdc++.h>
#define maxn 5019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n, m;
int mi[maxn], mi2[maxn];
int num[maxn];
bool isdist[maxn];

inline int dist(int x, int y){
	return (y > x) ? (y - x) : (n - x + y);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) mi[i] = n + 1;
	rep(i, 1, m) {
		scanf("%d%d", &x, &y);
		num[x]++;
		//mi[x] = min(mi[x], dist(x, y));
		if (dist(x, y) < mi[x]) mi[x] = dist(x, y), mi2[x] = y;
	}
	
	int mxnum = 0;
	rep(i, 1, n){
		mxnum = max(mxnum, num[i]);
	}
	int flag = 0;
	rep(i, 1, n) if (num[i] == mxnum) {
		if (mi2[i] < i) {
			mi2[i] = n + mi2[i];
		}
		flag = max(flag, mi2[i]);
	}
	
	rep(i, 1, n){
		printf("%d ", (mxnum - 1) * n + dist(i, flag));
		if (num[i] == mxnum) flag = max(flag, mi2[i] + n);
	}
	return 0;
}
