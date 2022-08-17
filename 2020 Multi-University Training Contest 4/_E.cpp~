#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define M 1000000007
#define mo(x) (x = (x >= M) ? (x - M) : x)
using namespace std;

int a[maxn], n;

int tim = 0;
int dp[maxn][2];
int vis[maxn][2];
int DP(int pos, int op){
	if (pos == 1) return 1;
	if (vis[pos][op] == tim) return dp[pos][op];
	vis[pos][op] = tim;
	int& ans = dp[pos][op]; ans = 0;
	if (!op && a[pos] != a[pos - 1]) ans += DP(pos - 1, 1), mo(ans);
	ans += DP(pos - 1, 0), mo(ans);
	return ans;
}

struct ele{
	char s[20];
	int l;
	void read(){
		scanf("%s", s);
		l = strlen(s);
	}
	/*
	bool operator == (const ele b) {
		if (l != b.l) return false;
		srep(i, 0, l) if (s[i] != b.s[i]) return false; 
		return true;
	}
	*/
	bool operator < (const ele b) const{
		if (l != b.l) return l < b.l;
		srep(i, 0, l) if (s[i] != b.s[i]) return s[i] < b.s[i]; 
		return false;
	}
}op; 
map<ele, int> id;

int ct = 0;
int main(){
	//init();
	int T; scanf("%d", &T);
	while (T--){
		ct = 0;
		++tim;
		scanf("%d", &n); 
		rep(i, 1, n) {
			op.read();
			if (!id.count(op)) id[op] = ++ct;
			a[i] = id[op];
		} 
		printf("%d\n", DP(n, 0));
		id.clear();
	}
	return 0;
}
