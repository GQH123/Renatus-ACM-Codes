#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 20
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, k;

int st[maxn][8];
int s[maxn];
char ss[8];
int times[20];

inline int add(int x){
	return (x == n) ? 1 : (x + 1);
}

int _st[8];
void give_min(int x){
	rep(i, 1, s[x]) times[st[x][i]]++; 
	int mi = 5;
	rep(i, 1, 13) {
		if (!times[i]) continue;
		mi = min(mi, times[i]);
	}
	int f = -1;
	rep(i, 1, 13){
		if (times[i] == mi) {
			f = i;
			break;
		}
	}
	bool ok = 0;
	int _s = 0;
	rep(i, 1, s[x]){
		if (st[x][i] == f && !ok) ok = 1;
		else _st[++_s] = st[x][i]; 
	}
	s[x] = _s;
	rep(i, 1, _s) st[x][i] = _st[i];
	rep(i, 1, 13) times[i] = 0;

	x = add(x);
	st[x][++s[x]] = f;
}

bool judge(int now){
	if (s[now] == 4 && now != k){
		int tt = st[now][1];
		rep(i, 1, 4) if (st[now][i] != tt) return false; 
		return true;
	}
	return false;
}

int JUDGE(int now){
	if (judge(now) && !judge(add(now))) return now;
	if (!judge(now) && judge(add(now))) return add(now);
	if (judge(now) && judge(add(now))) return min(now, add(now));
	return -1;
}

int main(){
	freopen("J.in", "r", stdin);
	scanf("%d%d", &n, &k);
	rep(i, 1, n){
		scanf("%s", ss + 1);
		rep(j, 1, 4){
			if (ss[j] == 'A') st[i][j] = 1;
			else if (ss[j] == 'D') st[i][j] = 10;
			else if (ss[j] == 'Q') st[i][j] = 11;
			else if (ss[j] == 'J') st[i][j] = 12;
			else if (ss[j] == 'K') st[i][j] = 13;
			else st[i][j] = ss[j] - '1' + 1;
		}
		s[i] = 4;
	}
	int ans = n + 1;
	rep(i, 1, n){
		if (judge(i)) {
			printf("%d", i);
			return 0;
		}
	}
	bool f = 1;
	int now = k;
	while (1){
		if (now == k){
			if (f){
				give_min(now);
				int d = JUDGE(now);
				if (d != -1) {ans = d; break;}
				now = add(now);
				f = 0;
			}
			else {
				k = add(k);
				f = 1;
				int d = JUDGE(now);
				if (d != -1) {ans = d; break;}
				now = add(now);
			}
		}
		else {
			give_min(now);
			int d = JUDGE(now);
			if (d != -1) {ans = d; break;}
			now = add(now);
		}
	}
	printf("%d", ans);
	return 0;
}

