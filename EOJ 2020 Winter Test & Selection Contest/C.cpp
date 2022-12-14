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
#define maxn 2000020
using namespace std;

int n;
char s[maxn];
bool iscon[30];
int id[30];
char rid[20];
int num[20][20];

int dp[20][1 << 20];
bool vis[20][1 << 20];
int DP(int pos, int op){
	if (pos == 19) return 0;
	if (vis[pos][op]) return dp[pos][op];
	vis[pos][op] = 1;
	int& ans = dp[pos][op];
	
	int sum = 0;
	srep(i, 0, pos) if (op & (1 << i)) sum += num[pos][i]; 
	ans = max(ans, sum + DP(pos + 1, op));
	
	sum = 0;
	srep(i, 0, pos) if (!(op & (1 << i))) sum += num[pos][i]; 
	ans = max(ans, sum + DP(pos + 1, op | (1 << pos)));
	
	return ans;
}

bool ifup[20];
void find_ans(int pos, int op){
	if (pos == 19) return;
	int ans = dp[pos][op];
	
	int sum = 0;
	srep(i, 0, pos) if (op & (1 << i)) sum += num[pos][i]; 
	if (sum + DP(pos + 1, op) == ans) {find_ans(pos + 1, op); return;} 
	//ans = max(ans, sum + DP(pos + 1, op));
	
	sum = 0;
	srep(i, 0, pos) if (!(op & (1 << i))) sum += num[pos][i]; 
	if (sum + DP(pos + 1, op | (1 << pos)) == ans) {ifup[pos] = 1, find_ans(pos + 1, op | (1 << pos)); return;}
	assert(false);
	//ans = max(ans, sum + DP(pos + 1, op | (1 << pos)));
	
	//return ans;
}

int main(){
	
		freopen("C.in", "r", stdin);
		
	scanf("%s", s + 1);
	n = strlen(s + 1);
	rep(i, 0, 25) iscon[i] = true;
	iscon['a' - 'a'] = iscon['e' - 'a'] = iscon['i' - 'a'] = iscon['o' - 'a'] = iscon['u' - 'a'] = iscon['y' - 'a'] = iscon['w' - 'a'] = false;
	int ptr = 0;
	rep(i, 0, 25){
		if (!iscon[i]) {id[i] = -1; continue;}
		id[i] = ptr, rid[ptr] = 'a' + i; ptr++;
	}
	srep(i, 1, n){
		if (!iscon[s[i] - 'a'] || !iscon[s[i + 1] - 'a']) continue;
		num[id[s[i] - 'a']][id[s[i + 1] - 'a']]++, num[id[s[i + 1] - 'a']][id[s[i] - 'a']]++;
	}
	//printf("%d\n", DP(0, 0));
	//printf("%d", DP(0, 0));
	DP(0, 0);
	find_ans(0, 0);
	rep(i, 1, n){
		if (!iscon[s[i] - 'a']) printf("%c", s[i]);
		else if (ifup[id[s[i] - 'a']]) printf("%c", s[i] - 'a' + 'A');
		else printf("%c", s[i]);
	}
	return 0;
}
