#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 3220
#define ll long long int 
using namespace std;

struct ele{
	int sum, last, num;
	ele(int sum, int last, int num) : sum(sum), last(last), num(num){}
	ele(){}
}sta[maxn * 80 * 30];
int cs = 0;

int n, k;
int bound; // = min(n, 75);
bool vis[maxn][80][30];
int dp[maxn][80][30];
int DP(int sum, int last, int num){
	if (!sum){
		if (!num) return 1;
		else return 0;
	}
	if (!num || last > bound || last > sum) return 0;
	if (vis[sum][last][num]) return dp[sum][last][num];
	vis[sum][last][num] = 1;
	sta[++cs] = ele(sum, last, num);
	int& ans = dp[sum][last][num];
	return ans = DP(sum - last, last + 1, num - 1) + DP(sum, last + 1, num);
}

struct sec{
	int sum, num;
	sec(int sum, int num) : sum(sum), num(num){}
	sec(){}
	bool operator < (const sec b) const{
		return (sum * b.num == num * b.sum) ? (num > b.num) : (sum * b.num < num * b.sum);
	}
}lis[maxn * 30];
int cl = 0;

int ans[80];
int ca = 0;
void Findans(int sum, int last, int num, int rank){
	if (!num) return;
	int k = DP(sum - last, last + 1, num - 1);
	if (rank > k) rank -= k;
	else {ans[++ca] = last, Findans(sum - last, last + 1, num - 1, rank); return;}
	Findans(sum, last + 1, num, rank);
}

struct query{
	int id, n, k;
	query(int id, int n, int k) : id(id), n(n), k(k){}
	query(){}
	bool operator < (const query b) const{
		return n < b.n;
	}
}q[120];
int out[120][30];
int s[120];

int main(){
	freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	rep(TT, 1, T) scanf("%d%d", &q[TT].n, &q[TT].k), q[TT].id = TT;
	sort(q + 1, q + 1 + T);
	q[0].n = -1;
	rep(TT, 1, T){
		n = q[TT].n, k = q[TT].k;
		if (q[TT - 1].n < 73 && n != q[TT - 1].n){
			while (cs){
				vis[sta[cs].sum][sta[cs].last][sta[cs].num] = dp[sta[cs].sum][sta[cs].last][sta[cs].num] = 0;
				cs--;
			}
		}
		bound = min(n, 73);
		int _num = min(n, 29);
		int _sum = (int)min((ll)n * (n + 1) >> 1, 3000ll);
		cl = 0;
		rep(i, 1, _num) rep(j, 1, _sum) lis[++cl] = sec(j, i); 
		sort(lis + 1, lis + 1 + cl);
		per(i, cl, 1){
			int num = DP(lis[i].sum, 1, lis[i].num);
			if (k > num) k -= num;
			else {
				_num = lis[i].num, _sum = lis[i].sum;
				break;
			}
		}
		Findans(_sum, 1, _num, k);
		rep(i, 1, ca) out[q[TT].id][i] = max(0, n - 73) + ans[i]; //printf("\n");
		s[q[TT].id] = ca;
		ca = 0;
	}
	rep(i, 1, T){
		printf("Case %d: ", i);
		rep(j, 1, s[i]) printf("%d ", out[i][j]); 
		printf("\n");
	}
	return 0;
}
