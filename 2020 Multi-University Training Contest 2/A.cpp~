#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400020
#define maxm 400020
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int 
#define pb push_back
using namespace std;


/*
struct ele{
	int x, y;
	ele(int x, int y) : x(x), y(y){}
	ele(){}
	bool operartor < (const edge b) const{
		return (
	}
}e[maxm];
*/
//pii e[maxm];
vector<int> G[maxn];

int n, m, b[maxn]; 
bool cmp(const int i, const int j){
	return (b[i] == b[j]) ? i < j : b[i] > b[j];
}

int num = 0;
int ufs[maxn], lis[maxn];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}

void merge(int x){
	int _x = find_root(x);
	num++;
	int si = G[x].size();
	srep(i, 0, si){
		int y = find_root(G[x][i]);
		if (_x == y) continue;
		else {
			num--;
			ufs[y] = _x;
		} 
	}
} 
int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", b + i), ufs[i] = lis[i] = i, num = 0;
		rep(i, 1, m) {
			scanf("%d%d", &x, &y);//e[i] = pii(x, y);
			if (cmp(x, y)) G[y].pb(x);
			else G[x].pb(y);
		} 
		sort(lis + 1, lis + 1 + n, cmp);
		ll res = 0;
		rep(i, 1, n){
			int x = lis[i];
			int nowb = b[x];
			while (i <= n && nowb == b[lis[i]]) {
				merge(lis[i]); 
				i++; 
			}
			int nexb = (i <= n) ? b[lis[i]] : 0;
			i--;
			res += 1ll * (nowb - nexb) * num;
		}
		printf("%lld\n", res);
		rep(i, 1, n) G[i].clear();
	}
	return 0;
}
