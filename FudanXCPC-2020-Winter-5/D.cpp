#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int
#define maxn 200020
#define maxm 
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n, k;
int d[maxn], fa[maxn];
int lis[maxn];

int tag[maxn];
int ans[maxn];

bool cmp(const int i, const int j){	
	return d[i] < d[j];
}
bool cmp2(const int i, const int j){	
	return ans[i] > ans[j];
}

int main(){
	freopen("D.in", "r", stdin);
	scanf("%d%d", &n, &k);
	rep(i, 2, n) scanf("%d", &fa[i]), d[i] = d[fa[i]] + 1;
	rep(i, 1, n) lis[i] = i;
	sort(lis + 1, lis + 1 + n, cmp);
	per(i, n, 1){
		int x = lis[i];
		if (!tag[x]) tag[x] = x;
		int y = tag[x];
		if (!tag[fa[x]]) tag[fa[x]] = y;
		else {
			if (d[y] > d[tag[fa[x]]]) tag[fa[x]] = y;
			else if (d[y] == d[tag[fa[x]]]){
				if (y < tag[fa[x]]) tag[fa[x]] = y;
			}
		}
	}
	rep(i, 1, n) ans[tag[i]]++, lis[i] = i;
	sort(lis + 1, lis + 1 + n, cmp2);
	int out = 0;
	rep(i, 1, k) out += ans[lis[i]];
	printf("%d", out);
	return 0;
}

